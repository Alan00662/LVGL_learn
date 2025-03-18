#include "lvgl/lvgl.h"
#include <stdio.h>

/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())


static const lv_font_t* font;       /* �������� */

static lv_obj_t *obj;   /* �������� */

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

    lv_obj_t *label = lv_label_create(lv_scr_act());                                        /* ����LED���ܱ�ǩ */
    lv_label_set_text(label, "LED 1");                                                     /* �����ı� */
    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                              /* �������� */
    lv_obj_align_to(label, led, LV_ALIGN_OUT_BOTTOM_MID, 0, scr_act_height() /15 );         /* ����λ�� */


}

static void lv_example_led_2(void)
{


    lv_obj_t* led = lv_led_create(obj);
    lv_obj_set_size(led,scr_act_height() /5 , scr_act_height() /5);
    lv_obj_align(led,LV_ALIGN_CENTER,0, -scr_act_height() /15);
    lv_led_off(led);
    lv_obj_add_event_cb(led,led_event_cb,LV_EVENT_CLICKED,NULL);

    lv_obj_t *label = lv_label_create(lv_scr_act());                                        /* ����LED���ܱ�ǩ */
    lv_label_set_text(label, "LED 2");                                                     /* �����ı� */
    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                              /* �������� */
    lv_obj_align_to(label, led, LV_ALIGN_OUT_BOTTOM_MID, 0, scr_act_height() /15 );         /* ����λ�� */


}

static void lv_example_led_3(void)
{


    lv_obj_t* led = lv_led_create(obj);
    lv_obj_set_size(led,scr_act_height() /5 , scr_act_height() /5);
    lv_obj_align(led,LV_ALIGN_CENTER,scr_act_width() * 4/ 15, -scr_act_height() /15);
    lv_led_off(led);
    lv_obj_add_event_cb(led,led_event_cb,LV_EVENT_CLICKED,NULL);

    lv_obj_t *label = lv_label_create(lv_scr_act());                                        /* ����LED���ܱ�ǩ */
    lv_label_set_text(label, "LED 3");                                                     /* �����ı� */
    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                              /* �������� */
    lv_obj_align_to(label, led, LV_ALIGN_OUT_BOTTOM_MID, 0, scr_act_height() /15 );         /* ����λ�� */

}

/**
 * @brief  LVGL��ʾ
 * @param  ��
 * @return ��
 */
void lv_mainstart(void)
{

    lv_example_led_1();
    lv_example_led_2();
    lv_example_led_3();
}
