#include "lvgl/lvgl.h"
#include <stdio.h>

/* 获取当前活动屏幕的宽高 */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())


static const lv_font_t* font;       /* 定义字体 */


static void keyboard_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t* target = lv_event_get_target(e);

    if(code == LV_EVENT_VALUE_CHANGED)
    {
        uint16_t id =lv_btnmatrix_get_selected_btn(target);
        const char* txt = lv_btnmatrix_get_btn_text(target,id);
        if(strcmp(txt,LV_SYMBOL_KEYBOARD) == 0)
        {
            if(lv_keyboard_get_mode(target) == LV_KEYBOARD_MODE_NUMBER)
            {
                lv_keyboard_set_mode(target,LV_KEYBOARD_MODE_TEXT_LOWER);
            }
            else
            {
                lv_keyboard_set_mode(target, LV_KEYBOARD_MODE_NUMBER);      /* 不是数字模式，则切换为数字模式 */
            }
        }
    }
}

static void lv_example_keyboard(void)
{
    lv_obj_t* textarea = lv_textarea_create(lv_scr_act());
    lv_obj_set_size(textarea,scr_act_width() - 10,scr_act_height()/2 - 10);
    lv_obj_align(textarea,LV_ALIGN_TOP_MID,0,0);

    lv_obj_t* keyboard = lv_keyboard_create(lv_scr_act());
    lv_keyboard_set_textarea(keyboard,textarea);
    lv_obj_add_event_cb(keyboard,keyboard_event_cb,LV_EVENT_VALUE_CHANGED,NULL);
}


/**
 * @brief  LVGL演示
 * @param  无
 * @return 无
 */
void lv_mainstart(void)
{

    lv_example_keyboard();
}
