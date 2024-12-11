/*
 * Copyright (c) 2018-2024, Andreas Kling <andreas@ladybird.org>
 * Copyright (c) 2021-2024, Sam Atkins <sam@ladybird.org>
 * Copyright (c) 2021, Tobias Christiansen <tobyase@serenityos.org>
 * Copyright (c) 2022-2023, MacDue <macdue@dueutil.tech>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibGfx/Font/FontStyleMapping.h>
#include <LibGfx/Font/FontWeight.h>
#include <LibWeb/CSS/CSSStyleValue.h>
#include <LibWeb/CSS/StyleValues/AbstractImageStyleValue.h>
#include <LibWeb/CSS/StyleValues/AngleStyleValue.h>
#include <LibWeb/CSS/StyleValues/BackgroundRepeatStyleValue.h>
#include <LibWeb/CSS/StyleValues/BackgroundSizeStyleValue.h>
#include <LibWeb/CSS/StyleValues/BasicShapeStyleValue.h>
#include <LibWeb/CSS/StyleValues/BorderRadiusStyleValue.h>
#include <LibWeb/CSS/StyleValues/CSSColorValue.h>
#include <LibWeb/CSS/StyleValues/CSSKeywordValue.h>
#include <LibWeb/CSS/StyleValues/CalculatedStyleValue.h>
#include <LibWeb/CSS/StyleValues/ConicGradientStyleValue.h>
#include <LibWeb/CSS/StyleValues/ContentStyleValue.h>
#include <LibWeb/CSS/StyleValues/CounterDefinitionsStyleValue.h>
#include <LibWeb/CSS/StyleValues/CounterStyleValue.h>
#include <LibWeb/CSS/StyleValues/CustomIdentStyleValue.h>
#include <LibWeb/CSS/StyleValues/DisplayStyleValue.h>
#include <LibWeb/CSS/StyleValues/EasingStyleValue.h>
#include <LibWeb/CSS/StyleValues/EdgeStyleValue.h>
#include <LibWeb/CSS/StyleValues/FilterValueListStyleValue.h>
#include <LibWeb/CSS/StyleValues/FlexStyleValue.h>
#include <LibWeb/CSS/StyleValues/FrequencyStyleValue.h>
#include <LibWeb/CSS/StyleValues/GridAutoFlowStyleValue.h>
#include <LibWeb/CSS/StyleValues/GridTemplateAreaStyleValue.h>
#include <LibWeb/CSS/StyleValues/GridTrackPlacementStyleValue.h>
#include <LibWeb/CSS/StyleValues/GridTrackSizeListStyleValue.h>
#include <LibWeb/CSS/StyleValues/ImageStyleValue.h>
#include <LibWeb/CSS/StyleValues/IntegerStyleValue.h>
#include <LibWeb/CSS/StyleValues/LengthStyleValue.h>
#include <LibWeb/CSS/StyleValues/LinearGradientStyleValue.h>
#include <LibWeb/CSS/StyleValues/MathDepthStyleValue.h>
#include <LibWeb/CSS/StyleValues/NumberStyleValue.h>
#include <LibWeb/CSS/StyleValues/OpenTypeTaggedStyleValue.h>
#include <LibWeb/CSS/StyleValues/PercentageStyleValue.h>
#include <LibWeb/CSS/StyleValues/PositionStyleValue.h>
#include <LibWeb/CSS/StyleValues/RadialGradientStyleValue.h>
#include <LibWeb/CSS/StyleValues/RatioStyleValue.h>
#include <LibWeb/CSS/StyleValues/RectStyleValue.h>
#include <LibWeb/CSS/StyleValues/ResolutionStyleValue.h>
#include <LibWeb/CSS/StyleValues/RotationStyleValue.h>
#include <LibWeb/CSS/StyleValues/ScaleStyleValue.h>
#include <LibWeb/CSS/StyleValues/ScrollbarGutterStyleValue.h>
#include <LibWeb/CSS/StyleValues/ShadowStyleValue.h>
#include <LibWeb/CSS/StyleValues/ShorthandStyleValue.h>
#include <LibWeb/CSS/StyleValues/StringStyleValue.h>
#include <LibWeb/CSS/StyleValues/StyleValueList.h>
#include <LibWeb/CSS/StyleValues/TimeStyleValue.h>
#include <LibWeb/CSS/StyleValues/TransformationStyleValue.h>
#include <LibWeb/CSS/StyleValues/TransitionStyleValue.h>
#include <LibWeb/CSS/StyleValues/TranslationStyleValue.h>
#include <LibWeb/CSS/StyleValues/URLStyleValue.h>
#include <LibWeb/CSS/StyleValues/UnresolvedStyleValue.h>

namespace Web::CSS {

CSSStyleValue::CSSStyleValue(Type type)
    : m_type(type)
{
}

AbstractImageStyleValue const& CSSStyleValue::as_abstract_image() const
{
    VERIFY(is_abstract_image());
    return static_cast<AbstractImageStyleValue const&>(*this);
}

AngleStyleValue const& CSSStyleValue::as_angle() const
{
    VERIFY(is_angle());
    return static_cast<AngleStyleValue const&>(*this);
}

BackgroundRepeatStyleValue const& CSSStyleValue::as_background_repeat() const
{
    VERIFY(is_background_repeat());
    return static_cast<BackgroundRepeatStyleValue const&>(*this);
}

BackgroundSizeStyleValue const& CSSStyleValue::as_background_size() const
{
    VERIFY(is_background_size());
    return static_cast<BackgroundSizeStyleValue const&>(*this);
}

BasicShapeStyleValue const& CSSStyleValue::as_basic_shape() const
{
    VERIFY(is_basic_shape());
    return static_cast<BasicShapeStyleValue const&>(*this);
}

BorderRadiusStyleValue const& CSSStyleValue::as_border_radius() const
{
    VERIFY(is_border_radius());
    return static_cast<BorderRadiusStyleValue const&>(*this);
}

CalculatedStyleValue const& CSSStyleValue::as_calculated() const
{
    VERIFY(is_calculated());
    return static_cast<CalculatedStyleValue const&>(*this);
}

CSSColorValue const& CSSStyleValue::as_color() const
{
    VERIFY(is_color());
    return static_cast<CSSColorValue const&>(*this);
}

ConicGradientStyleValue const& CSSStyleValue::as_conic_gradient() const
{
    VERIFY(is_conic_gradient());
    return static_cast<ConicGradientStyleValue const&>(*this);
}

ContentStyleValue const& CSSStyleValue::as_content() const
{
    VERIFY(is_content());
    return static_cast<ContentStyleValue const&>(*this);
}

CounterStyleValue const& CSSStyleValue::as_counter() const
{
    VERIFY(is_counter());
    return static_cast<CounterStyleValue const&>(*this);
}

CounterDefinitionsStyleValue const& CSSStyleValue::as_counter_definitions() const
{
    VERIFY(is_counter_definitions());
    return static_cast<CounterDefinitionsStyleValue const&>(*this);
}

CustomIdentStyleValue const& CSSStyleValue::as_custom_ident() const
{
    VERIFY(is_custom_ident());
    return static_cast<CustomIdentStyleValue const&>(*this);
}

DisplayStyleValue const& CSSStyleValue::as_display() const
{
    VERIFY(is_display());
    return static_cast<DisplayStyleValue const&>(*this);
}

EasingStyleValue const& CSSStyleValue::as_easing() const
{
    VERIFY(is_easing());
    return static_cast<EasingStyleValue const&>(*this);
}

EdgeStyleValue const& CSSStyleValue::as_edge() const
{
    VERIFY(is_edge());
    return static_cast<EdgeStyleValue const&>(*this);
}

FilterValueListStyleValue const& CSSStyleValue::as_filter_value_list() const
{
    VERIFY(is_filter_value_list());
    return static_cast<FilterValueListStyleValue const&>(*this);
}

FlexStyleValue const& CSSStyleValue::as_flex() const
{
    VERIFY(is_flex());
    return static_cast<FlexStyleValue const&>(*this);
}

FrequencyStyleValue const& CSSStyleValue::as_frequency() const
{
    VERIFY(is_frequency());
    return static_cast<FrequencyStyleValue const&>(*this);
}

GridAutoFlowStyleValue const& CSSStyleValue::as_grid_auto_flow() const
{
    VERIFY(is_grid_auto_flow());
    return static_cast<GridAutoFlowStyleValue const&>(*this);
}

GridTemplateAreaStyleValue const& CSSStyleValue::as_grid_template_area() const
{
    VERIFY(is_grid_template_area());
    return static_cast<GridTemplateAreaStyleValue const&>(*this);
}

GridTrackPlacementStyleValue const& CSSStyleValue::as_grid_track_placement() const
{
    VERIFY(is_grid_track_placement());
    return static_cast<GridTrackPlacementStyleValue const&>(*this);
}

GridTrackSizeListStyleValue const& CSSStyleValue::as_grid_track_size_list() const
{
    VERIFY(is_grid_track_size_list());
    return static_cast<GridTrackSizeListStyleValue const&>(*this);
}

CSSKeywordValue const& CSSStyleValue::as_keyword() const
{
    VERIFY(is_keyword());
    return static_cast<CSSKeywordValue const&>(*this);
}

ImageStyleValue const& CSSStyleValue::as_image() const
{
    VERIFY(is_image());
    return static_cast<ImageStyleValue const&>(*this);
}

IntegerStyleValue const& CSSStyleValue::as_integer() const
{
    VERIFY(is_integer());
    return static_cast<IntegerStyleValue const&>(*this);
}

LengthStyleValue const& CSSStyleValue::as_length() const
{
    VERIFY(is_length());
    return static_cast<LengthStyleValue const&>(*this);
}

LinearGradientStyleValue const& CSSStyleValue::as_linear_gradient() const
{
    VERIFY(is_linear_gradient());
    return static_cast<LinearGradientStyleValue const&>(*this);
}

MathDepthStyleValue const& CSSStyleValue::as_math_depth() const
{
    VERIFY(is_math_depth());
    return static_cast<MathDepthStyleValue const&>(*this);
}

NumberStyleValue const& CSSStyleValue::as_number() const
{
    VERIFY(is_number());
    return static_cast<NumberStyleValue const&>(*this);
}

OpenTypeTaggedStyleValue const& CSSStyleValue::as_open_type_tagged() const
{
    VERIFY(is_open_type_tagged());
    return static_cast<OpenTypeTaggedStyleValue const&>(*this);
}

PercentageStyleValue const& CSSStyleValue::as_percentage() const
{
    VERIFY(is_percentage());
    return static_cast<PercentageStyleValue const&>(*this);
}

PositionStyleValue const& CSSStyleValue::as_position() const
{
    VERIFY(is_position());
    return static_cast<PositionStyleValue const&>(*this);
}

RadialGradientStyleValue const& CSSStyleValue::as_radial_gradient() const
{
    VERIFY(is_radial_gradient());
    return static_cast<RadialGradientStyleValue const&>(*this);
}

RatioStyleValue const& CSSStyleValue::as_ratio() const
{
    VERIFY(is_ratio());
    return static_cast<RatioStyleValue const&>(*this);
}

RectStyleValue const& CSSStyleValue::as_rect() const
{
    VERIFY(is_rect());
    return static_cast<RectStyleValue const&>(*this);
}

ResolutionStyleValue const& CSSStyleValue::as_resolution() const
{
    VERIFY(is_resolution());
    return static_cast<ResolutionStyleValue const&>(*this);
}

RotationStyleValue const& CSSStyleValue::as_rotation() const
{
    VERIFY(is_rotation());
    return static_cast<RotationStyleValue const&>(*this);
}

ScaleStyleValue const& CSSStyleValue::as_scale() const
{
    VERIFY(is_scale());
    return static_cast<ScaleStyleValue const&>(*this);
}

ScrollbarGutterStyleValue const& CSSStyleValue::as_scrollbar_gutter() const
{
    VERIFY(is_scrollbar_gutter());
    return static_cast<ScrollbarGutterStyleValue const&>(*this);
}

ShadowStyleValue const& CSSStyleValue::as_shadow() const
{
    VERIFY(is_shadow());
    return static_cast<ShadowStyleValue const&>(*this);
}

ShorthandStyleValue const& CSSStyleValue::as_shorthand() const
{
    VERIFY(is_shorthand());
    return static_cast<ShorthandStyleValue const&>(*this);
}

StringStyleValue const& CSSStyleValue::as_string() const
{
    VERIFY(is_string());
    return static_cast<StringStyleValue const&>(*this);
}

TimeStyleValue const& CSSStyleValue::as_time() const
{
    VERIFY(is_time());
    return static_cast<TimeStyleValue const&>(*this);
}

TransformationStyleValue const& CSSStyleValue::as_transformation() const
{
    VERIFY(is_transformation());
    return static_cast<TransformationStyleValue const&>(*this);
}

TransitionStyleValue const& CSSStyleValue::as_transition() const
{
    VERIFY(is_transition());
    return static_cast<TransitionStyleValue const&>(*this);
}

TranslationStyleValue const& CSSStyleValue::as_translation() const
{
    VERIFY(is_translation());
    return static_cast<TranslationStyleValue const&>(*this);
}

UnresolvedStyleValue const& CSSStyleValue::as_unresolved() const
{
    VERIFY(is_unresolved());
    return static_cast<UnresolvedStyleValue const&>(*this);
}

URLStyleValue const& CSSStyleValue::as_url() const
{
    VERIFY(is_url());
    return static_cast<URLStyleValue const&>(*this);
}

StyleValueList const& CSSStyleValue::as_value_list() const
{
    VERIFY(is_value_list());
    return static_cast<StyleValueList const&>(*this);
}

ValueComparingNonnullRefPtr<CSSStyleValue const> CSSStyleValue::absolutized(CSSPixelRect const&, Length::FontMetrics const&, Length::FontMetrics const&) const
{
    return *this;
}

bool CSSStyleValue::has_auto() const
{
    return is_keyword() && as_keyword().keyword() == Keyword::Auto;
}

Keyword CSSStyleValue::to_keyword() const
{
    if (is_keyword())
        return as_keyword().keyword();
    return Keyword::Invalid;
}

int CSSStyleValue::to_font_weight() const
{
    if (is_keyword()) {
        switch (as_keyword().keyword()) {
        case Keyword::Normal:
            return Gfx::FontWeight::Regular;
        case Keyword::Bold:
            return Gfx::FontWeight::Bold;
        case Keyword::Lighter:
            // FIXME: This should be relative to the parent.
            return Gfx::FontWeight::Regular;
        case Keyword::Bolder:
            // FIXME: This should be relative to the parent.
            return Gfx::FontWeight::Bold;
        default:
            return Gfx::FontWeight::Regular;
        }
    }
    if (is_number()) {
        return round_to<int>(as_number().number());
    }
    if (is_calculated()) {
        auto maybe_weight = as_calculated().resolve_integer();
        if (maybe_weight.has_value())
            return maybe_weight.value();
    }
    return Gfx::FontWeight::Regular;
}

int CSSStyleValue::to_font_slope() const
{
    // FIXME: Implement oblique <angle>
    if (is_keyword()) {
        switch (as_keyword().keyword()) {
        case Keyword::Italic: {
            static int italic_slope = Gfx::name_to_slope("Italic"sv);
            return italic_slope;
        }
        case Keyword::Oblique:
            static int oblique_slope = Gfx::name_to_slope("Oblique"sv);
            return oblique_slope;
        case Keyword::Normal:
        default:
            break;
        }
    }
    static int normal_slope = Gfx::name_to_slope("Normal"sv);
    return normal_slope;
}

int CSSStyleValue::to_font_width() const
{
    int width = Gfx::FontWidth::Normal;
    if (is_keyword()) {
        switch (as_keyword().keyword()) {
        case Keyword::UltraCondensed:
            width = Gfx::FontWidth::UltraCondensed;
            break;
        case Keyword::ExtraCondensed:
            width = Gfx::FontWidth::ExtraCondensed;
            break;
        case Keyword::Condensed:
            width = Gfx::FontWidth::Condensed;
            break;
        case Keyword::SemiCondensed:
            width = Gfx::FontWidth::SemiCondensed;
            break;
        case Keyword::Normal:
            width = Gfx::FontWidth::Normal;
            break;
        case Keyword::SemiExpanded:
            width = Gfx::FontWidth::SemiExpanded;
            break;
        case Keyword::Expanded:
            width = Gfx::FontWidth::Expanded;
            break;
        case Keyword::ExtraExpanded:
            width = Gfx::FontWidth::ExtraExpanded;
            break;
        case Keyword::UltraExpanded:
            width = Gfx::FontWidth::UltraExpanded;
            break;
        default:
            break;
        }
    } else if (is_percentage()) {
        float percentage = as_percentage().percentage().value();
        if (percentage <= 50) {
            width = Gfx::FontWidth::UltraCondensed;
        } else if (percentage <= 62.5f) {
            width = Gfx::FontWidth::ExtraCondensed;
        } else if (percentage <= 75.0f) {
            width = Gfx::FontWidth::Condensed;
        } else if (percentage <= 87.5f) {
            width = Gfx::FontWidth::SemiCondensed;
        } else if (percentage <= 100.0f) {
            width = Gfx::FontWidth::Normal;
        } else if (percentage <= 112.5f) {
            width = Gfx::FontWidth::SemiExpanded;
        } else if (percentage <= 125.0f) {
            width = Gfx::FontWidth::Expanded;
        } else if (percentage <= 150.0f) {
            width = Gfx::FontWidth::ExtraExpanded;
        } else {
            width = Gfx::FontWidth::UltraExpanded;
        }
    }
    return width;
}

Optional<Gfx::FontVariantAlternates> CSSStyleValue::to_font_variant_alternates() const
{
    VERIFY(is_keyword());
    switch (as_keyword().keyword()) {
    case Keyword::Normal:
        return {};
    case Keyword::HistoricalForms:
        return Gfx::FontVariantAlternates { .historical_forms = true };
    default:
        VERIFY_NOT_REACHED();
    }
}

Optional<FontVariantCaps> CSSStyleValue::to_font_variant_caps() const
{
    VERIFY(is_keyword());
    return keyword_to_font_variant_caps(as_keyword().keyword());
}

Optional<Gfx::FontVariantEastAsian> CSSStyleValue::to_font_variant_east_asian() const
{
    VERIFY(is_value_list());
    auto& list = as_value_list();
    Gfx::FontVariantEastAsian east_asian {};
    for (auto& value : list.values()) {
        VERIFY(value->is_keyword());
        switch (value->as_keyword().keyword()) {
        case Keyword::Normal:
            return {};
        case Keyword::Jis78:
            east_asian.variant = Gfx::FontVariantEastAsian::Variant::Jis78;
            break;
        case Keyword::Jis83:
            east_asian.variant = Gfx::FontVariantEastAsian::Variant::Jis83;
            break;
        case Keyword::Jis90:
            east_asian.variant = Gfx::FontVariantEastAsian::Variant::Jis90;
            break;
        case Keyword::Jis04:
            east_asian.variant = Gfx::FontVariantEastAsian::Variant::Jis04;
            break;
        case Keyword::Simplified:
            east_asian.variant = Gfx::FontVariantEastAsian::Variant::Simplified;
            break;
        case Keyword::Traditional:
            east_asian.variant = Gfx::FontVariantEastAsian::Variant::Traditional;
            break;
        case Keyword::FullWidth:
            east_asian.width = Gfx::FontVariantEastAsian::Width::FullWidth;
            break;
        case Keyword::ProportionalWidth:
            east_asian.width = Gfx::FontVariantEastAsian::Width::Proportional;
            break;
        case Keyword::Ruby:
            east_asian.ruby = true;
            break;
        default:
            VERIFY_NOT_REACHED();
            break;
        }
    }
    return east_asian;
}

Optional<FontVariantEmoji> CSSStyleValue::to_font_variant_emoji() const
{
    VERIFY(is_keyword());
    return keyword_to_font_variant_emoji(as_keyword().keyword());
}

Optional<Gfx::FontVariantLigatures> CSSStyleValue::to_font_variant_ligatures() const
{
    if (!is_value_list()) {
        return {};
    }
    auto const& list = as_value_list();
    Gfx::FontVariantLigatures ligatures {};

    for (auto& value : list.values()) {
        if (!value->is_keyword())
            continue;
        switch (value->as_keyword().keyword()) {
        case Keyword::Normal:
            return {};
        case Keyword::None:
            ligatures.none = true;
            return ligatures;
        case Keyword::CommonLigatures:
            ligatures.common = Gfx::FontVariantLigatures::Common::Common;
            break;
        case Keyword::NoCommonLigatures:
            ligatures.common = Gfx::FontVariantLigatures::Common::NoCommon;
            break;
        case Keyword::DiscretionaryLigatures:
            ligatures.discretionary = Gfx::FontVariantLigatures::Discretionary::Discretionary;
            break;
        case Keyword::NoDiscretionaryLigatures:
            ligatures.discretionary = Gfx::FontVariantLigatures::Discretionary::NoDiscretionary;
            break;
        case Keyword::HistoricalLigatures:
            ligatures.historical = Gfx::FontVariantLigatures::Historical::Historical;
            break;
        case Keyword::NoHistoricalLigatures:
            ligatures.historical = Gfx::FontVariantLigatures::Historical::NoHistorical;
            break;
        case Keyword::Contextual:
            ligatures.contextual = Gfx::FontVariantLigatures::Contextual::Contextual;
            break;
        case Keyword::NoContextual:
            ligatures.contextual = Gfx::FontVariantLigatures::Contextual::NoContextual;
            break;
        default:
            VERIFY_NOT_REACHED();
            break;
        }
    }
    return ligatures;
}

Optional<Gfx::FontVariantNumeric> CSSStyleValue::to_font_variant_numeric() const
{
    VERIFY(is_value_list());
    auto& list = as_value_list();
    Gfx::FontVariantNumeric numeric {};
    for (auto& value : list.values()) {
        VERIFY(value->is_keyword());
        switch (value->as_keyword().keyword()) {
        case Keyword::Normal:
            return {};
        case Keyword::Ordinal:
            numeric.ordinal = true;
            break;
        case Keyword::SlashedZero:
            numeric.slashed_zero = true;
            break;
        case Keyword::OldstyleNums:
            numeric.figure = Gfx::FontVariantNumeric::Figure::Oldstyle;
            break;
        case Keyword::LiningNums:
            numeric.figure = Gfx::FontVariantNumeric::Figure::Lining;
            break;
        case Keyword::ProportionalNums:
            numeric.spacing = Gfx::FontVariantNumeric::Spacing::Proportional;
            break;
        case Keyword::TabularNums:
            numeric.spacing = Gfx::FontVariantNumeric::Spacing::Tabular;
            break;
        case Keyword::DiagonalFractions:
            numeric.fraction = Gfx::FontVariantNumeric::Fraction::Diagonal;
            break;
        case Keyword::StackedFractions:
            numeric.fraction = Gfx::FontVariantNumeric::Fraction::Stacked;
            break;
        default:
            VERIFY_NOT_REACHED();
            break;
        }
    }
    return numeric;
}

Optional<FontVariantPosition> CSSStyleValue::to_font_variant_position() const
{
    VERIFY(is_keyword());
    return keyword_to_font_variant_position(as_keyword().keyword());
}

}
