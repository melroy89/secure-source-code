//! `flash.media.SoundTransform` builtin/prototype

use crate::avm2::activation::Activation;
use crate::avm2::class::{Class, ClassAttributes};
use crate::avm2::method::{Method, NativeMethodImpl};
use crate::avm2::object::{Object, TObject};
use crate::avm2::value::Value;
use crate::avm2::Error;
use crate::avm2::Multiname;
use crate::avm2::Namespace;
use crate::avm2::QName;
use gc_arena::{GcCell, MutationContext};

/// Implements `flash.media.SoundTransform`'s instance constructor.
pub fn instance_init<'gc>(
    activation: &mut Activation<'_, 'gc>,
    this: Option<Object<'gc>>,
    args: &[Value<'gc>],
) -> Result<Value<'gc>, Error<'gc>> {
    if let Some(mut this) = this {
        activation.super_init(this, &[])?;

        let volume = args
            .get(0)
            .cloned()
            .unwrap_or_else(|| 1.0.into())
            .coerce_to_number(activation)?;
        let pan = args
            .get(1)
            .cloned()
            .unwrap_or_else(|| 0.0.into())
            .coerce_to_number(activation)?;

        this.set_property(&Multiname::public("volume"), volume.into(), activation)?;
        this.set_property(&Multiname::public("pan"), pan.into(), activation)?;
    }

    Ok(Value::Undefined)
}

/// Implements `flash.media.SoundTransform`'s class constructor.
pub fn class_init<'gc>(
    _activation: &mut Activation<'_, 'gc>,
    _this: Option<Object<'gc>>,
    _args: &[Value<'gc>],
) -> Result<Value<'gc>, Error<'gc>> {
    Ok(Value::Undefined)
}

/// Implements `SoundTransform.pan`'s getter.
pub fn pan<'gc>(
    activation: &mut Activation<'_, 'gc>,
    this: Option<Object<'gc>>,
    _args: &[Value<'gc>],
) -> Result<Value<'gc>, Error<'gc>> {
    if let Some(this) = this {
        let left_to_right = this
            .get_property(&Multiname::public("leftToRight"), activation)?
            .coerce_to_number(activation)?;
        let right_to_left = this
            .get_property(&Multiname::public("rightToLeft"), activation)?
            .coerce_to_number(activation)?;

        if left_to_right != 0.0 || right_to_left != 0.0 {
            return Ok(0.0.into());
        }

        let left_to_left = this
            .get_property(&Multiname::public("leftToLeft"), activation)?
            .coerce_to_number(activation)?;

        return Ok((1.0 - left_to_left.powf(2.0).abs()).into());
    }

    Ok(Value::Undefined)
}

/// Implements `SoundTransform.pan`'s setter.
pub fn set_pan<'gc>(
    activation: &mut Activation<'_, 'gc>,
    this: Option<Object<'gc>>,
    args: &[Value<'gc>],
) -> Result<Value<'gc>, Error<'gc>> {
    if let Some(mut this) = this {
        let pan = args
            .get(0)
            .cloned()
            .unwrap_or(Value::Undefined)
            .coerce_to_number(activation)?;

        this.set_property(
            &Multiname::public("leftToLeft"),
            (1.0 - pan).sqrt().into(),
            activation,
        )?;
        this.set_property(
            &Multiname::public("rightToRight"),
            (1.0 + pan).sqrt().into(),
            activation,
        )?;
        this.set_property(&Multiname::public("leftToRight"), (0.0).into(), activation)?;
        this.set_property(&Multiname::public("rightToLeft"), (0.0).into(), activation)?;
    }

    Ok(Value::Undefined)
}

/// Construct `SoundTransform`'s class.
pub fn create_class<'gc>(mc: MutationContext<'gc, '_>) -> GcCell<'gc, Class<'gc>> {
    let class = Class::new(
        QName::new(Namespace::package("flash.media"), "SoundTransform"),
        Some(Multiname::public("Object")),
        Method::from_builtin(instance_init, "<SoundTransform instance initializer>", mc),
        Method::from_builtin(class_init, "<SoundTransform class initializer>", mc),
        mc,
    );

    let mut write = class.write(mc);

    write.set_attributes(ClassAttributes::SEALED | ClassAttributes::FINAL);

    const PUBLIC_INSTANCE_PROPERTIES: &[(
        &str,
        Option<NativeMethodImpl>,
        Option<NativeMethodImpl>,
    )] = &[("pan", Some(pan), Some(set_pan))];
    write.define_public_builtin_instance_properties(mc, PUBLIC_INSTANCE_PROPERTIES);

    const PUBLIC_INSTANCE_SLOTS: &[(&str, Option<f64>)] = &[
        ("leftToLeft", None),
        ("leftToRight", None),
        ("rightToLeft", None),
        ("rightToRight", None),
        ("volume", None),
    ];
    write.define_public_slot_number_instance_traits(PUBLIC_INSTANCE_SLOTS);

    class
}