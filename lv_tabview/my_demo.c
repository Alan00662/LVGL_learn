#include "lvgl/lvgl.h"
#include <stdio.h>

/* 获取当前活动屏幕的宽高 */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())


static const lv_font_t* font;       /* 定义字体 */

static void lv_example_tabview(void)
{
    font = &lv_font_montserrat_14;
    lv_obj_t *tabview = lv_tabview_create(lv_scr_act(),LV_DIR_TOP,scr_act_height()/7);
    lv_obj_set_style_text_font(tabview,font,LV_STATE_DEFAULT);

    lv_obj_t *tab1 = lv_tabview_add_tab(tabview,"Message");
    lv_obj_t *tab2 = lv_tabview_add_tab(tabview,"Schedule");
    lv_obj_t *tab3 = lv_tabview_add_tab(tabview,"Meeting");

    lv_obj_t *label1 = lv_label_create(tab1);
    lv_label_set_text(label1,"Tonight's meeting cancelled.");
    lv_obj_center(label1);

    lv_obj_t *label2 = lv_label_create(tab2);
    lv_label_set_text(label2,"AM   8:30   meet the client\n\n" "PM   13:30   factory tour");
    lv_obj_center(label2);

    lv_obj_t *label3 = lv_label_create(tab3);
    lv_label_set_text(label3,"None");
    lv_obj_center(label3);

    lv_obj_t* btn = lv_tabview_get_tab_btns(tabview);
    lv_obj_set_style_bg_color(btn,lv_color_hex(0xb7472a), LV_PART_ITEMS|LV_STATE_DEFAULT);     /* 设置按钮背景颜色：橙色 */
        lv_obj_set_style_bg_opa(btn, 200, LV_PART_ITEMS|LV_STATE_DEFAULT);                          /* 设置按钮背景透明度 */
    lv_obj_set_style_text_color(btn, lv_color_hex(0xf3f3f3), LV_PART_ITEMS|LV_STATE_DEFAULT);   /* 设置按钮文本颜色：白色 */
}




/**
 * @brief  LVGL演示
 * @param  无
 * @return 无
 */
void lv_mainstart(void)
{

    lv_example_tabview();
}
