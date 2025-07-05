#include "lvgl/lvgl.h"
#include <stdio.h>

/* 获取当前活动屏幕的宽高 */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())

/* 定义图片部件、滑块部件 */
static uint8_t cool_mode_state = 0;                         /* 制冷模式状态：0，关闭；1，开启 */
static uint8_t warm_mode_state = 0;                         /* 制暖模式状态：0，关闭；1，开启 */
static uint8_t dry_mode_state = 0;                          /* 干燥模式状态：0，关闭；1，开启 */
static lv_point_t line_points[] = {{0,0},{0,120}};          /* 直线坐标数组 */

LV_IMG_DECLARE(img_cool);                           /* 声明图片 */
LV_IMG_DECLARE(img_dry);                           /* 声明图片 */
LV_IMG_DECLARE(img_warm);                           /* 声明图片 */

static const lv_font_t *font;                               /* 定义字体 */

static void cool_event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);
    if(cool_mode_state == 0)
    {
        cool_mode_state = 1;
        lv_obj_set_style_img_recolor_opa(target,255,0);
        lv_obj_set_style_img_recolor(target,lv_color_hex(0x00a9ff),0);
    }
    else
    {
        cool_mode_state = 0;
        lv_obj_set_style_img_recolor_opa(target,255,0);
        lv_obj_set_style_img_recolor(target,lv_color_hex(0x8a8a8a),0);
    }
}

static void warm_event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);
    if(warm_mode_state == 0)
    {
        warm_mode_state = 1;
        lv_obj_set_style_img_recolor_opa(target,255,0);
        lv_obj_set_style_img_recolor(target,lv_color_hex(0x00a9ff),0);
    }
    else
    {
        warm_mode_state = 0;
        lv_obj_set_style_img_recolor_opa(target,255,0);
        lv_obj_set_style_img_recolor(target,lv_color_hex(0x8a8a8a),0);
    }
}

static void dry_event_cb(lv_event_t* e)
{
    lv_obj_t* target = lv_event_get_target(e);
    if(dry_mode_state == 0)
    {
        dry_mode_state = 1;
        lv_obj_set_style_img_recolor_opa(target,255,0);
        lv_obj_set_style_img_recolor(target,lv_color_hex(0x00a9ff),0);
    }
    else
    {
        dry_mode_state = 0;
        lv_obj_set_style_img_recolor_opa(target,255,0);
        lv_obj_set_style_img_recolor(target,lv_color_hex(0x8a8a8a),0);
    }
}

static void lv_example_imgbtn(void)
{
    font = &lv_font_montserrat_14;
    lv_obj_t* obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj,scr_act_width()-10, 200);
    lv_obj_align(obj,LV_ALIGN_CENTER,0,0);

    lv_obj_t* imgbtn_cool = lv_imgbtn_create(obj);
    lv_imgbtn_set_src(imgbtn_cool,LV_IMGBTN_STATE_RELEASED,NULL,&img_cool,NULL);
    lv_obj_set_size(imgbtn_cool,64,64);
    lv_obj_align(imgbtn_cool,LV_ALIGN_CENTER,-scr_act_width()/3,-15);
    lv_obj_add_event_cb(imgbtn_cool,cool_event_cb,LV_EVENT_PRESSED,NULL);

    lv_obj_t* label_cool = lv_label_create(obj);
    lv_label_set_text(label_cool,"Cool");
    lv_obj_set_style_text_font(label_cool,font,0);
    lv_obj_align_to(label_cool,imgbtn_cool,LV_ALIGN_OUT_BOTTOM_MID,0,10);


    lv_obj_t* imgbtn_warm = lv_imgbtn_create(obj);
    lv_imgbtn_set_src(imgbtn_warm,LV_IMGBTN_STATE_RELEASED,NULL,&img_warm,NULL);
    lv_obj_set_size(imgbtn_warm,64,64);
    lv_obj_align(imgbtn_warm,LV_ALIGN_CENTER,0,-15);
    lv_obj_add_event_cb(imgbtn_warm,warm_event_cb,LV_EVENT_PRESSED,NULL);

    lv_obj_t* label_warm = lv_label_create(obj);
    lv_label_set_text(label_warm,"Warm");
    lv_obj_set_style_text_font(label_warm,font,0);
    lv_obj_align_to(label_warm,imgbtn_warm,LV_ALIGN_OUT_BOTTOM_MID,0,10);

    lv_obj_t* imgbtn_dry = lv_imgbtn_create(obj);
    lv_imgbtn_set_src(imgbtn_dry,LV_IMGBTN_STATE_RELEASED,NULL,&img_dry,NULL);
    lv_obj_set_size(imgbtn_dry,64,64);
    lv_obj_align(imgbtn_dry,LV_ALIGN_CENTER,scr_act_width()/3,-15);
    lv_obj_add_event_cb(imgbtn_dry,dry_event_cb,LV_EVENT_PRESSED,NULL);

    lv_obj_t* label_dry = lv_label_create(obj);
    lv_label_set_text(label_dry,"Warm");
    lv_obj_set_style_text_font(label_dry,font,0);
    lv_obj_align_to(label_dry,imgbtn_dry,LV_ALIGN_OUT_BOTTOM_MID,0,10);

}
/**
 * @brief  LVGL演示
 * @param  无
 * @return 无
 */
void lv_mainstart(void)
{
    lv_example_imgbtn();

}
