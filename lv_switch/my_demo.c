#include "lvgl/lvgl.h"
#include <stdio.h>

/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())

#if (1 != LV_FONT_MONTSERRAT_10 || 1 != LV_FONT_MONTSERRAT_14 || 1 != LV_FONT_MONTSERRAT_20)
    #error Please Make Sure Enable LV_FONT_MONTSERRAT_10 & LV_FONT_MONTSERRAT_14 & LV_FONT_MONTSERRAT_20
#endif

static const lv_font_t* font;       /* �������� */

static lv_obj_t *switch_cool;            /* ����ģʽ���� */
static lv_obj_t *switch_heat;            /* ��ůģʽ���� */
static lv_obj_t *switch_dry;             /* ����ģʽ���� */

static void switch_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);                      /* ��ȡ����Դ */

    if(target == switch_cool)                                       /* ���俪�ش��� */
    {
        if(lv_obj_has_state(switch_cool, LV_STATE_CHECKED))         /* �жϿ���״̬ */
        {
            lv_obj_clear_state(switch_heat, LV_STATE_CHECKED);      /* ����ģʽ�Ѵ򿪣��ر���ůģʽ */
        }
    }
    else if(target == switch_heat)                                  /* ��ů���ش��� */
    {
        if(lv_obj_has_state(switch_heat, LV_STATE_CHECKED))         /* �жϿ���״̬ */
        {
            lv_obj_clear_state(switch_cool, LV_STATE_CHECKED);      /* ��ůģʽ�Ѵ򿪣��ر�����ģʽ */
        }
    }

}

static void lv_example_label(void)
{
     font = &lv_font_montserrat_14;

    lv_obj_t *label = lv_label_create(lv_scr_act());                            /* ������ǩ */
    lv_label_set_text(label, "Control  Center");                                /* �����ı����� */
    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                  /* �������� */
    lv_obj_align(label, LV_ALIGN_CENTER, 0, -scr_act_height() / 3 );            /* ����λ�� */
}

static void lv_example_switch1(void)
{
    /* ����ģʽ�������󣨾��α����� */
    lv_obj_t *obj_cool = lv_obj_create(lv_scr_act());                               /* ������������ */
    lv_obj_set_size(obj_cool,scr_act_height() / 3, scr_act_height() / 3 );          /* ���ô�С */
    lv_obj_align(obj_cool, LV_ALIGN_CENTER, -scr_act_width() / 4, 0 );              /* ����λ�� */

    /* ����ģʽ���ر�ǩ */
    lv_obj_t *label_cool = lv_label_create(obj_cool);                               /* ������ǩ */
    lv_label_set_text(label_cool, "Cool");                                          /* �����ı����� */
    lv_obj_set_style_text_font(label_cool, font, LV_STATE_DEFAULT);                 /* �������� */
    lv_obj_align(label_cool, LV_ALIGN_CENTER, 0, -scr_act_height() / 16 );          /* ����λ�� */

    /* ����ģʽ���� */
    switch_cool = lv_switch_create(obj_cool);                                       /* �������� */
    lv_obj_set_size(switch_cool,scr_act_height() / 6, scr_act_height() / 12 );      /* ���ô�С */
    lv_obj_align(switch_cool, LV_ALIGN_CENTER, 0, scr_act_height() / 16 );          /* ����λ�� */
    lv_obj_add_event_cb(switch_cool, switch_event_cb, LV_EVENT_VALUE_CHANGED, NULL);/* ����¼� */
}

static void lv_example_switch2(void)
{
    /* ��ůģʽ�������󣨾��α����� */
    lv_obj_t *obj_heat = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj_heat,scr_act_height() / 3, scr_act_height() / 3 );
    lv_obj_align(obj_heat, LV_ALIGN_CENTER, 0, 0 );

    /* ��ůģʽ���ر�ǩ */
    lv_obj_t *label_heat = lv_label_create(obj_heat);
    lv_label_set_text(label_heat, "Heat");
    lv_obj_set_style_text_font(label_heat, font, LV_STATE_DEFAULT);
    lv_obj_align(label_heat, LV_ALIGN_CENTER, 0, -scr_act_height() / 16 );

    /* ��ůģʽ���� */
    switch_heat = lv_switch_create(obj_heat);
    lv_obj_set_size(switch_heat,scr_act_height() / 6, scr_act_height() / 12 );
    lv_obj_align(switch_heat, LV_ALIGN_CENTER, 0, scr_act_height() / 16 );
    lv_obj_add_event_cb(switch_heat, switch_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
}

static void lv_example_switch3(void)
{
    /* ����ģʽ�������󣨾��α����� */
    lv_obj_t *obj_dry = lv_obj_create(lv_scr_act());
    lv_obj_set_size(obj_dry,scr_act_height() / 3, scr_act_height() / 3 );
    lv_obj_align(obj_dry, LV_ALIGN_CENTER, scr_act_width() / 4, 0 );

    /* ����ģʽ���ر�ǩ */
    lv_obj_t *label_dry = lv_label_create(obj_dry);
    lv_label_set_text(label_dry, "Dry");
    lv_obj_set_style_text_font(label_dry, font, LV_STATE_DEFAULT);
    lv_obj_align(label_dry, LV_ALIGN_CENTER, 0, -scr_act_height() / 16 );

    /* ����ģʽ���� */
    switch_dry = lv_switch_create(obj_dry);
    lv_obj_set_size(switch_dry,scr_act_height() / 6, scr_act_height() / 12 );
    lv_obj_align(switch_dry, LV_ALIGN_CENTER, 0, scr_act_height() / 16 );
    lv_obj_add_state(switch_dry, LV_STATE_CHECKED|LV_STATE_DISABLED);
}

/**
 * @brief  LVGL��ʾ
 * @param  ��
 * @return ��
 */
void lv_mainstart(void)
{
    lv_example_label();
    lv_example_switch1();
    lv_example_switch2();
    lv_example_switch3();

}
