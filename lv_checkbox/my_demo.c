#include "lvgl/lvgl.h"
#include <stdio.h>

/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())

static const lv_font_t *font;                   /* �������� */

static int16_t aggregate = 0;                   /* �����ܼ۸� */

static lv_obj_t *label_menu;                    /* �˵������ǩ */
static lv_obj_t *label_aggregate;               /* �ܼ۸��ǩ */

/* ���帴ѡ�� */
static lv_obj_t *checkbox1;
static lv_obj_t *checkbox2;
static lv_obj_t *checkbox3;
static lv_obj_t *checkbox4;

/**
 * @brief  �ص��¼�
 * @param  *e ���¼���ز����ļ��ϣ��������˸��¼�����������
 * @return ��
 */
static void checkbox_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);                              /* ��ȡ����Դ */

    if(target == checkbox1)                                                 /* ��ѡ��1���� */
    {
        lv_obj_has_state(checkbox1, LV_STATE_CHECKED) ? (aggregate += 19) : (aggregate -= 19);
    }
    else if(target == checkbox2)                                            /* ��ѡ��2���� */
    {
        lv_obj_has_state(checkbox2, LV_STATE_CHECKED) ? (aggregate += 29) : (aggregate -= 29);
    }
        else if(target == checkbox3)                                            /* ��ѡ��2���� */
    {
        lv_obj_has_state(checkbox3, LV_STATE_CHECKED) ? (aggregate += 39) : (aggregate -= 39);
    }

    lv_label_set_text_fmt(label_aggregate, "Aggregate  :  $%d", aggregate); /* �����ܼ۸��ǩ */
}

/**
 * @brief  ���⡢�ܼ۸��ǩ
 * @param  ��
 * @return ��
 */
static void lv_example_label(void)
{
    /* ���ݻ��Ļ���ѡ������ */
     font = &lv_font_montserrat_14;


    /* �˵������ǩ */
    label_menu = lv_label_create(lv_scr_act());
    lv_label_set_text(label_menu, "MENU");
    lv_obj_set_style_text_font(label_menu, font, LV_STATE_DEFAULT);
    lv_obj_align(label_menu, LV_ALIGN_CENTER, 0, -scr_act_height() * 2 / 5 );

    /* �ܼ۸��ǩ */
    label_aggregate = lv_label_create(lv_scr_act());
    lv_label_set_text(label_aggregate, "Aggregate  :  $0");
    lv_obj_set_style_text_font(label_aggregate, font, LV_STATE_DEFAULT);
    lv_obj_align(label_aggregate, LV_ALIGN_CENTER, 0, scr_act_height() * 2 / 5 );
}

/**
 * @brief  ��Ʒ��ѡ��
 * @param  ��
 * @return ��
 */
static void lv_example_checkbox(void)
{
    /* ��������������Ϊ���� */
    lv_obj_t *obj = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj, scr_act_width() * 4 /5 , scr_act_height() * 3 /5);
    lv_obj_align(obj, LV_ALIGN_CENTER, 0 , 0);

    /* ��Ʒ1��ѡ�� */
    checkbox1 = lv_checkbox_create(obj);
    lv_checkbox_set_text(checkbox1, "Roast chicken     $19");
    lv_obj_set_style_text_font(checkbox1, font, LV_STATE_DEFAULT);
    lv_obj_align(checkbox1, LV_ALIGN_LEFT_MID, 0, -scr_act_height() / 5 );
    lv_obj_add_event_cb(checkbox1, checkbox_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    /* ��Ʒ2��ѡ�� */
    checkbox2 = lv_checkbox_create(obj);
    lv_checkbox_set_text(checkbox2, "Roast duck     $29");
    lv_obj_set_style_text_font(checkbox2, font, LV_STATE_DEFAULT);
    lv_obj_align_to(checkbox2, checkbox1, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 16);
    lv_obj_add_event_cb(checkbox2, checkbox_event_cb, LV_EVENT_VALUE_CHANGED, NULL);

    /* ��Ʒ3��ѡ�� */
    checkbox3 = lv_checkbox_create(obj);
    lv_checkbox_set_text(checkbox3, "Roast fish     $39");
    lv_obj_set_style_text_font(checkbox3, font, LV_STATE_DEFAULT);
    lv_obj_align_to(checkbox3, checkbox2, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 16);
        lv_obj_add_event_cb(checkbox3, checkbox_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    //lv_obj_add_state(checkbox3, LV_STATE_DISABLED);

    checkbox4 = lv_checkbox_create(obj);
    lv_checkbox_set_text(checkbox4,"Roast lamb      $15");
    lv_obj_set_style_text_font(checkbox4,font,LV_STATE_DEFAULT);
    lv_obj_align_to(checkbox4,checkbox3, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 16);
    lv_obj_add_state(checkbox4, LV_STATE_DISABLED);
}

/**
 * @brief  LVGL��ʾ
 * @param  ��
 * @return ��
 */
void lv_mainstart(void)
{
    lv_example_label();
    lv_example_checkbox();
}
