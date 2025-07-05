#include "lvgl/lvgl.h"
#include <stdio.h>

/* 获取当前活动屏幕的宽高 */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())

/* 定义图片部件、滑块部件 */
static lv_obj_t *list;              /* 定义列表 */
static lv_obj_t *list_label;        /* 定义标签 */

static const lv_font_t *font;                               /* 定义字体 */

static void list_btn_event_cb(lv_event_t* e)
{
    lv_obj_t* list_btn = lv_event_get_target(e);

    lv_label_set_text(list_label,lv_list_get_btn_text(list,list_btn));
    lv_obj_add_state(list_btn,LV_STATE_FOCUS_KEY);

}

static void lv_example_list(void)
{
    font = &lv_font_montserrat_16;
    lv_obj_t* obj_left = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj_left,scr_act_width() * 0.6,scr_act_height() * 0.9);
    lv_obj_align(obj_left,LV_ALIGN_LEFT_MID,5,0);
    lv_obj_update_layout(obj_left);

    lv_obj_t* obj_right = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj_right,scr_act_width() * 0.4-15,scr_act_height() * 0.9);
    lv_obj_align_to(obj_right,obj_left,LV_ALIGN_OUT_RIGHT_MID,5,0);
    lv_obj_update_layout(obj_right);

    list_label = lv_label_create(obj_right);
    lv_obj_set_size(list_label,lv_obj_get_width(obj_right)-13,scr_act_height() * 0.9);
    lv_obj_align(list_label,LV_ALIGN_TOP_MID,0,5);
    lv_obj_update_layout(list_label);
    lv_label_set_text(list_label,"New");
    lv_obj_set_style_text_font(list_label,font,LV_PART_MAIN);

    list = lv_list_create(obj_left);
    lv_obj_set_size(list,lv_obj_get_width(obj_left) * 0.8,lv_obj_get_height(obj_left) * 0.9);
    lv_obj_center(list);
    lv_obj_set_style_text_font(list,font,LV_PART_MAIN);

    lv_obj_t* btn;
    lv_list_add_text(list,"File");
    btn = lv_list_add_btn(list,LV_SYMBOL_FILE,"New");
    lv_obj_add_event_cb(btn,list_btn_event_cb,LV_EVENT_CLICKED,NULL);
        btn = lv_list_add_btn(list,LV_SYMBOL_DIRECTORY,"Open");
    lv_obj_add_event_cb(btn,list_btn_event_cb,LV_EVENT_CLICKED,NULL);
        btn = lv_list_add_btn(list,LV_SYMBOL_SAVE,"Save");
    lv_obj_add_event_cb(btn,list_btn_event_cb,LV_EVENT_CLICKED,NULL);
        btn = lv_list_add_btn(list,LV_SYMBOL_CLOSE,"Delete");
    lv_obj_add_event_cb(btn,list_btn_event_cb,LV_EVENT_CLICKED,NULL);
            btn = lv_list_add_btn(list,LV_SYMBOL_EDIT,"Edit");
    lv_obj_add_event_cb(btn,list_btn_event_cb,LV_EVENT_CLICKED,NULL);

        lv_list_add_text(list,"Connectivity");
    btn = lv_list_add_btn(list,LV_SYMBOL_BLUETOOTH,"Bluetooth");
    lv_obj_add_event_cb(btn,list_btn_event_cb,LV_EVENT_CLICKED,NULL);
        btn = lv_list_add_btn(list,LV_SYMBOL_GPS,"Navigation");
    lv_obj_add_event_cb(btn,list_btn_event_cb,LV_EVENT_CLICKED,NULL);
        btn = lv_list_add_btn(list,LV_SYMBOL_USB,"USB");
    lv_obj_add_event_cb(btn,list_btn_event_cb,LV_EVENT_CLICKED,NULL);
        btn = lv_list_add_btn(list,LV_SYMBOL_BATTERY_FULL,"Battery");
    lv_obj_add_event_cb(btn,list_btn_event_cb,LV_EVENT_CLICKED,NULL);

        lv_list_add_text(list,"Exit");
    btn = lv_list_add_btn(list,LV_SYMBOL_OK,"Apply");
    lv_obj_add_event_cb(btn,list_btn_event_cb,LV_EVENT_CLICKED,NULL);
        btn = lv_list_add_btn(list,LV_SYMBOL_CLOSE,"Close");
    lv_obj_add_event_cb(btn,list_btn_event_cb,LV_EVENT_CLICKED,NULL);

}


/**
 * @brief  LVGL演示
 * @param  无
 * @return 无
 */
void lv_mainstart(void)
{
    lv_example_list();

}
