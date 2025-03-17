#include "lvgl/lvgl.h"
#include <stdio.h>

/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())

#if (1 != LV_FONT_MONTSERRAT_10 || 1 != LV_FONT_MONTSERRAT_14 || 1 != LV_FONT_MONTSERRAT_20)
    #error Please Make Sure Enable LV_FONT_MONTSERRAT_10 & LV_FONT_MONTSERRAT_14 & LV_FONT_MONTSERRAT_20
#endif

static const lv_font_t* font;       /* �������� */

static lv_obj_t *label_speed;       /* �ٶ���ʾ�ı� */
static lv_obj_t *btn_speed_up;      /* ���ٰ�ť */
static lv_obj_t *btn_speed_down;    /* ���ٰ�ť */
static lv_obj_t *btn_stop;          /* ��ͣ��ť */

static int32_t speed_val = 0;       /* �ٶ�ֵ */

/**
 * @brief  ��ť�ص�
 * @param  *e ���¼���ز����ļ��ϣ��������˸��¼�����������
 * @return ��
 */
static void btn_event_cb(lv_event_t * e)
{
    lv_obj_t *target = lv_event_get_target(e);      /* ��ȡ����Դ */

    if(target == btn_speed_up)                      /* ���ٰ�ť */
    {
        speed_val += 30;
    }
    else if(target == btn_speed_down)               /* ���ٰ�ť */
    {
        speed_val -= 30;
    }
    else if(target == btn_stop)                     /* ��ͣ��ť */
    {
        speed_val = 0;
    }
    lv_label_set_text_fmt(label_speed, "Speed : %d RPM", speed_val);    /* �����ٶ�ֵ */
}

/**
 * @brief  �ٶ�ֵ��ʾ��ǩ
 * @param  ��
 * @return ��
 */
static void lv_example_label(void)
{
    /* ���ݻ��Ļ���ѡ������ */
    if (scr_act_width() <= 320)
    {
        font = &lv_font_montserrat_10;
    }
    else if (scr_act_width() <= 480)
    {
        font = &lv_font_montserrat_14;
    }
    else
    {
        font = &lv_font_montserrat_20;
    }

    label_speed = lv_label_create(lv_scr_act());                                    /* �����ٶ���ʾ��ǩ */
    lv_obj_set_style_text_font(label_speed, font, LV_PART_MAIN);                    /* �������� */
    lv_label_set_text(label_speed, "Speed :   RPM");                                /* �����ı� */
    lv_obj_align(label_speed, LV_ALIGN_CENTER, 0, -scr_act_height() / 3);           /* ���ñ�ǩλ�� */
}
/**
 * @brief  ���ٰ�ť
 * @param  ��
 * @return ��
 */
static void lv_example_btn_up(void)
{
    btn_speed_up = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn_speed_up,scr_act_width() / 4,scr_act_height() / 6);
    lv_obj_align(btn_speed_up,LV_ALIGN_CENTER, -scr_act_width() / 3,0);
    lv_obj_add_event_cb(btn_speed_up,btn_event_cb,LV_EVENT_CLICKED,NULL);

    lv_obj_t* label = lv_label_create(btn_speed_up);
    lv_obj_set_style_text_font(label,font,LV_PART_MAIN);
    lv_label_set_text(label,"Speed +");
    lv_obj_set_align(label,LV_ALIGN_CENTER);

}

/**
 * @brief  ���ٰ�ť
 * @param  ��
 * @return ��
 */
static void lv_example_btn_down(void)
{
    btn_speed_down = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn_speed_down,scr_act_width() / 4,scr_act_height() / 6);
    lv_obj_align(btn_speed_down,LV_ALIGN_CENTER, 0,0);
    lv_obj_add_event_cb(btn_speed_down,btn_event_cb,LV_EVENT_CLICKED,NULL);

    lv_obj_t* label = lv_label_create(btn_speed_down);
    lv_obj_set_style_text_font(label,font,LV_PART_MAIN);
    lv_label_set_text(label,"Speed -");
    lv_obj_set_align(label,LV_ALIGN_CENTER);

}

/**
 * @brief  ���ٰ�ť
 * @param  ��
 * @return ��
 */
static void lv_example_btn_stop(void)
{
    btn_stop = lv_btn_create(lv_scr_act());
    lv_obj_set_size(btn_stop,scr_act_width() / 4,scr_act_height() / 6);
    lv_obj_align(btn_stop,LV_ALIGN_CENTER, scr_act_width() / 3,0);
    lv_obj_set_style_bg_color(btn_stop,lv_color_hex(0xef5f60),LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(btn_stop, lv_color_hex(0xff0000), LV_STATE_PRESSED);  /* ���ð�ť������ɫ�����£� */
    lv_obj_add_event_cb(btn_stop,btn_event_cb,LV_EVENT_CLICKED,NULL);


    lv_obj_t* label = lv_label_create(btn_stop);
    lv_obj_set_style_text_font(label,font,LV_PART_MAIN);
    lv_label_set_text(label,"Stop");
    lv_obj_set_align(label,LV_ALIGN_CENTER);

}

/**
 * @brief  LVGL��ʾ
 * @param  ��
 * @return ��
 */
void lv_mainstart(void)
{
    lv_example_label();
    lv_example_btn_up();
    lv_example_btn_down();
    lv_example_btn_stop();
}
