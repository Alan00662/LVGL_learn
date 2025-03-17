#include "lvgl/lvgl.h"
#include <stdio.h>

/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())

#if (1 != LV_FONT_MONTSERRAT_10 || 1 != LV_FONT_MONTSERRAT_14 || 1 != LV_FONT_MONTSERRAT_20)
    #error Please Make Sure Enable LV_FONT_MONTSERRAT_10 & LV_FONT_MONTSERRAT_14 & LV_FONT_MONTSERRAT_20
#endif

static const lv_font_t* font;       /* �������� */

static lv_obj_t *slider_label;                                                      /* �������ٷֱȱ�ǩ */

static void slider_event_cb(lv_event_t *e)
{
    lv_obj_t *target = lv_event_get_target(e);                                      /* ��ȡ����Դ */
    lv_event_code_t code = lv_event_get_code(e);                                    /* ��ȡ�¼����� */

    if(code == LV_EVENT_VALUE_CHANGED)
    {
        lv_label_set_text_fmt(slider_label, "%d%%", lv_slider_get_value(target));   /* ��ȡ��ǰֵ�����½������ٷֱ� */
    }
}

static void lv_example_slider(void)
{
    font = &lv_font_montserrat_14;

        /* ���� */
    lv_obj_t * slider = lv_slider_create(lv_scr_act());                             /* �������� */
    lv_obj_set_size(slider, scr_act_width() / 2, 20);                               /* ���ô�С */
    lv_obj_center(slider);                                                          /* ����λ�� */
    lv_slider_set_value(slider, 50, LV_ANIM_OFF);                                   /* ���õ�ǰֵ */
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);     /* ����¼� */

    /* �ٷֱȱ�ǩ */
    slider_label = lv_label_create(lv_scr_act());                                   /* �����ٷֱȱ�ǩ */
    lv_label_set_text(slider_label, "50%");                                         /* �����ı����� */
    lv_obj_set_style_text_font(slider_label, font, LV_STATE_DEFAULT);               /* �������� */
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_RIGHT_MID, 20, 0);           /* ����λ�� */

        /* ����ͼ�� */
    lv_obj_t *sound_label = lv_label_create(lv_scr_act());                          /* ����������ǩ */
    lv_label_set_text(sound_label, LV_SYMBOL_VOLUME_MAX);                           /* �����ı����ݣ�����ͼ�� */
    lv_obj_set_style_text_font(sound_label, font, LV_STATE_DEFAULT);                /* �������� */
    lv_obj_align_to(sound_label, slider, LV_ALIGN_OUT_LEFT_MID, -20, 0);            /* ����λ�� */

}



/**
 * @brief  LVGL��ʾ
 * @param  ��
 * @return ��
 */
void lv_mainstart(void)
{
    lv_example_slider();
}
