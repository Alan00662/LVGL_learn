#include "lvgl/lvgl.h"
#include <stdio.h>

/* 获取当前活动屏幕的宽高 */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())

#if (1 != LV_FONT_MONTSERRAT_10 || 1 != LV_FONT_MONTSERRAT_14 || 1 != LV_FONT_MONTSERRAT_20)
    #error Please Make Sure Enable LV_FONT_MONTSERRAT_10 & LV_FONT_MONTSERRAT_14 & LV_FONT_MONTSERRAT_20
#endif

static const lv_font_t* font;       /* 定义字体 */

static lv_obj_t *slider_label;                                                      /* 进度条百分比标签 */

static void slider_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);                                      /* 获取触发源 */
    lv_event_code_t code = lv_event_get_code(e);                                    /* 获取事件类型 */

    if(code == LV_EVENT_VALUE_CHANGED)
    {
        lv_label_set_text_fmt(slider_label, "%d%%", lv_slider_get_value(target));   /* 获取当前值，更新进度条百分比 */
    }
}

static void lv_example_slider(void)
{
    font = &lv_font_montserrat_14;

        /* 滑块 */
    lv_obj_t * slider = lv_slider_create(lv_scr_act());                             /* 创建滑块 */
    lv_obj_set_size(slider, scr_act_width() / 2, 20);                               /* 设置大小 */
    lv_obj_center(slider);                                                          /* 设置位置 */
    lv_slider_set_value(slider, 50, LV_ANIM_OFF);                                   /* 设置当前值 */
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);     /* 添加事件 */

    /* 百分比标签 */
    slider_label = lv_label_create(lv_scr_act());                                   /* 创建百分比标签 */
    lv_label_set_text(slider_label, "50%");                                         /* 设置文本内容 */
    lv_obj_set_style_text_font(slider_label, font, LV_STATE_DEFAULT);               /* 设置字体 */
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_RIGHT_MID, 20, 0);           /* 设置位置 */

        /* 音量图标 */
    lv_obj_t *sound_label = lv_label_create(lv_scr_act());                          /* 创建音量标签 */
    lv_label_set_text(sound_label, LV_SYMBOL_VOLUME_MAX);                           /* 设置文本内容：音量图标 */
    lv_obj_set_style_text_font(sound_label, font, LV_STATE_DEFAULT);                /* 设置字体 */
    lv_obj_align_to(sound_label, slider, LV_ALIGN_OUT_LEFT_MID, -20, 0);            /* 设置位置 */

}



/**
 * @brief  LVGL演示
 * @param  无
 * @return 无
 */
void lv_mainstart(void)
{
    lv_example_slider();
}
