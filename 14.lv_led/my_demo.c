#include "lvgl/lvgl.h"
#include <stdio.h>

/* 获取当前活动屏幕的宽高 */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())


static const lv_font_t* font;       /* 定义字体 */

static lv_obj_t *obj;   /* 基础对象 */

static void led_event_cb(lv_event_t* e)
{
    lv_obj_t* led = lv_event_get_target(e);
    lv_led_toggle(led);
}

static void lv_example_led_1(void)
{
    font = &lv_font_montserrat_14;
    obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj,scr_act_width() * 5 /6,scr_act_height()*3/5);
    lv_obj_align(obj,LV_ALIGN_CENTER,0,0);
    lv_obj_set_style_bg_color(obj,lv_color_hex(0xefefef), LV_STATE_DEFAULT);

    lv_obj_t* led = lv_led_create(obj);
    lv_obj_set_size(led,scr_act_height() /5 , scr_act_height() /5);
    lv_obj_align(led,LV_ALIGN_CENTER,-scr_act_width() * 4/ 15, -scr_act_height() /15);
    lv_led_off(led);
    lv_obj_add_event_cb(led,led_event_cb,LV_EVENT_CLICKED,NULL);

    lv_obj_t *label = lv_label_create(lv_scr_act());                                        /* 创建LED功能标签 */
    lv_label_set_text(label, "LED 1");                                                     /* 设置文本 */
    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                              /* 设置字体 */
    lv_obj_align_to(label, led, LV_ALIGN_OUT_BOTTOM_MID, 0, scr_act_height() /15 );         /* 设置位置 */


}

static void lv_example_led_2(void)
{


    lv_obj_t* led = lv_led_create(obj);
    lv_obj_set_size(led,scr_act_height() /5 , scr_act_height() /5);
    lv_obj_align(led,LV_ALIGN_CENTER,0, -scr_act_height() /15);
    lv_led_off(led);
    lv_obj_add_event_cb(led,led_event_cb,LV_EVENT_CLICKED,NULL);

    lv_obj_t *label = lv_label_create(lv_scr_act());                                        /* 创建LED功能标签 */
    lv_label_set_text(label, "LED 2");                                                     /* 设置文本 */
    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                              /* 设置字体 */
    lv_obj_align_to(label, led, LV_ALIGN_OUT_BOTTOM_MID, 0, scr_act_height() /15 );         /* 设置位置 */


}

static void lv_example_led_3(void)
{


    lv_obj_t* led = lv_led_create(obj);
    lv_obj_set_size(led,scr_act_height() /5 , scr_act_height() /5);
    lv_obj_align(led,LV_ALIGN_CENTER,scr_act_width() * 4/ 15, -scr_act_height() /15);
    lv_led_off(led);
    lv_obj_add_event_cb(led,led_event_cb,LV_EVENT_CLICKED,NULL);

    lv_obj_t *label = lv_label_create(lv_scr_act());                                        /* 创建LED功能标签 */
    lv_label_set_text(label, "LED 3");                                                     /* 设置文本 */
    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                              /* 设置字体 */
    lv_obj_align_to(label, led, LV_ALIGN_OUT_BOTTOM_MID, 0, scr_act_height() /15 );         /* 设置位置 */

}

/**
 * @brief  LVGL演示
 * @param  无
 * @return 无
 */
void lv_mainstart(void)
{

    lv_example_led_1();
    lv_example_led_2();
    lv_example_led_3();
}
