#include "lvgl/lvgl.h"
#include <stdio.h>

/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())

#if (1 != LV_FONT_MONTSERRAT_10 || 1 != LV_FONT_MONTSERRAT_14 || 1 != LV_FONT_MONTSERRAT_20)
    #error Please Make Sure Enable LV_FONT_MONTSERRAT_10 & LV_FONT_MONTSERRAT_14 & LV_FONT_MONTSERRAT_20
#endif

static const lv_font_t* font;       /* �������� */

/* ģʽѡ�� */
static const char *mode_options = "Auto\n"
                                    "Heat\n"
                                    "Cool\n"
                                    "Fan";
/* �¶�ѡ�� */
static const char *temp_options = "23\n"
                                    "24\n"
                                    "25\n"
                                    "26\n"
                                    "27\n"
                                    "28\n"
                                    "29";
/* ʪ��ѡ�� */
static const char *hum_options  = "30\n"
                                    "40\n"
                                    "50\n"
                                    "60\n"
                                    "70\n"
                                    "80\n"
                                    "90";

static lv_obj_t *temp_roller;                   /* �¶ȹ��� */
static lv_obj_t *hum_roller;                    /* ʪ�ȹ��� */

static void roller_event_cb(lv_event_t* e)
{
    lv_obj_t *target = lv_event_get_target(e);

    if(lv_roller_get_selected(target) == 0)     /*��0����Ҳ����ѡ��Auto��ʱ��*/
    {
         lv_obj_add_state(temp_roller, LV_STATE_DISABLED);       /* �����¶ȹ���Ϊ����ѡ״̬ */
        lv_obj_add_state(hum_roller, LV_STATE_DISABLED);        /* ������ʪ�ȹ���Ϊ����ѡ״̬ */
    }
        else
    {
        lv_obj_clear_state(temp_roller, LV_STATE_DISABLED);     /* ����¶ȹ��ֲ���ѡ״̬ */
        lv_obj_clear_state(hum_roller, LV_STATE_DISABLED);      /* ���ʪ�ȹ��ֲ���ѡ״̬ */
    }
}
static void lv_example_roller1(void)
{
    font = &lv_font_montserrat_14;

    lv_obj_t *mode_roller = lv_roller_create(lv_scr_act());                                     /* ����ģʽ���ù��� */
    lv_roller_set_options(mode_roller, mode_options, LV_ROLLER_MODE_NORMAL);                    /* �������ѡ���������ģʽ */
    lv_obj_align(mode_roller, LV_ALIGN_CENTER, -scr_act_width() / 4, 0);                        /* ���ù���λ�� */
    lv_obj_set_width(mode_roller, scr_act_width() / 6);                                         /* ���ù��ֿ�� */
    lv_obj_set_style_text_font(mode_roller, font, LV_STATE_DEFAULT);                            /* ���ù������� */
    lv_roller_set_visible_row_count(mode_roller, 3);                                            /* ���ù��ֿɼ�ѡ����� */
    lv_roller_set_selected(mode_roller, 2, LV_ANIM_OFF);                                        /* ���ù��ֵ�ǰ��ѡ�� */
    lv_obj_add_event_cb(mode_roller, roller_event_cb, LV_EVENT_VALUE_CHANGED, NULL);            /* ����¼��ص� */

}

/**
 * @brief  �¶�����
 * @param  ��
 * @return ��
 */
static void lv_example_roller2(void)
{
    temp_roller = lv_roller_create(lv_scr_act());                                               /* �����¶����ù��� */
    lv_roller_set_options(temp_roller, temp_options, LV_ROLLER_MODE_NORMAL);                    /* �������ѡ���������ģʽ */
    lv_obj_align(temp_roller, LV_ALIGN_CENTER, 0, 0);                                           /* ���ù���λ�� */
    lv_obj_set_width(temp_roller, scr_act_width() / 6);                                         /* ���ù��ֿ�� */
    lv_obj_set_style_text_font(temp_roller, font, LV_STATE_DEFAULT);                            /* ���ù������� */
    lv_roller_set_visible_row_count(temp_roller, 3);                                            /* ���ù��ֿɼ�ѡ����� */
    lv_roller_set_selected(temp_roller, 2, LV_ANIM_OFF);                                        /* ���ù��ֵ�ǰ��ѡ�� */

    lv_obj_t *label = lv_label_create(lv_scr_act());                                            /* ������ǩ */
    lv_label_set_text(label, "TEMP");                                                           /* �����ı����� */
    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                                  /* �������� */
    lv_obj_align_to(label, temp_roller, LV_ALIGN_OUT_TOP_MID, 0, -15 );                         /* ����λ�� */
}

static void lv_example_roller3(void)
{
    hum_roller = lv_roller_create(lv_scr_act());                                                /* ����ʪ�����ù��� */
    lv_roller_set_options(hum_roller, hum_options, LV_ROLLER_MODE_NORMAL);                      /* �������ѡ���������ģʽ */
    lv_obj_align(hum_roller, LV_ALIGN_CENTER, scr_act_width() / 4, 0);                          /* ���ù���λ�� */
    lv_obj_set_width(hum_roller, scr_act_width() / 6);                                          /* ���ù��ֿ�� */
    lv_obj_set_style_text_font(hum_roller, font, LV_STATE_DEFAULT);                             /* ���ù������� */
    lv_roller_set_visible_row_count(hum_roller, 3);                                             /* ���ù��ֿɼ�ѡ����� */
    lv_roller_set_selected(hum_roller, 2, LV_ANIM_OFF);                                         /* ���ù��ֵ�ǰ��ѡ�� */

    lv_obj_t *label = lv_label_create(lv_scr_act());                                            /* ������ǩ */
    lv_label_set_text(label, "HUM");                                                            /* �����ı����� */
    lv_obj_set_style_text_font(label, font, LV_STATE_DEFAULT);                                  /* �������� */
    lv_obj_align_to(label, hum_roller, LV_ALIGN_OUT_TOP_MID, 0, -15 );                          /* ����λ�� */
}


/**
 * @brief  LVGL��ʾ
 * @param  ��
 * @return ��
 */
void lv_mainstart(void)
{
    lv_example_roller1();
    lv_example_roller2();
    lv_example_roller3();
}
