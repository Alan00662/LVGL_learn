#include "lvgl/lvgl.h"
#include <stdio.h>

/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())


static const lv_font_t* font;       /* �������� */

static lv_obj_t *msgbox;                                                            /* ��Ϣ�� */
static lv_obj_t *slider_label;                                                      /* �����ٷֱȱ�ǩ */

static void slider_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);            /* ��ȡ�¼����� */
    lv_obj_t *target = lv_event_get_target(e);              /* ��ȡ����Դ */

    if(code == LV_EVENT_VALUE_CHANGED)                            /* �¼����ͣ����۽� */
    {
        lv_label_set_text_fmt(slider_label, "%d%%", lv_slider_get_value(target));   /* ��ȡ��ǰֵ�����������ٷֱ� */

        if(lv_slider_get_value(target) > 80)                                        /* ��������80% */
        {
            lv_obj_clear_flag(msgbox, LV_OBJ_FLAG_HIDDEN);                          /* �����Ϣ���������ԣ����ֵ�����ʾ */
        }
    }

}

static void lv_example_slider(void)
{
    /* ���� */
    lv_obj_t * slider = lv_slider_create(lv_scr_act());                                 /* �������� */
    lv_obj_set_size(slider, scr_act_width() / 2, 20);                                   /* ���ô�С */
    lv_obj_center(slider);                                                              /* ����λ�� */
    lv_slider_set_value(slider, 50, LV_ANIM_OFF);                                       /* ���õ�ǰֵ */
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);         /* ����¼� */

    /* �ٷֱȱ�ǩ */
    slider_label = lv_label_create(lv_scr_act());                                       /* �����ٷֱȱ�ǩ */
    lv_label_set_text(slider_label, "50%");                                             /* �����ı����� */
    lv_obj_set_style_text_font(slider_label, &lv_font_montserrat_20, LV_STATE_DEFAULT); /* �������� */
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_RIGHT_MID, 20, 0);               /* ����λ�� */

    /* ����ͼ�� */
    lv_obj_t *sound_label = lv_label_create(lv_scr_act());                              /* ����������ǩ */
    lv_label_set_text(sound_label, LV_SYMBOL_VOLUME_MAX);                               /* �����ı����ݣ�����ͼ�� */
    lv_obj_set_style_text_font(sound_label, &lv_font_montserrat_20, LV_STATE_DEFAULT);  /* �������� */
    lv_obj_align_to(sound_label, slider, LV_ALIGN_OUT_LEFT_MID, -20, 0);                /* ����λ�� */
}

static void msgbox_event_cb(lv_event_t* e)
{
    lv_obj_t *target = lv_event_get_current_target(e);                 /* ��ȡ��ǰ����Դ */

    if(lv_msgbox_get_active_btn(target) == 2)                          /* ��ȡ��ť���� */
    {
        lv_obj_add_flag(msgbox, LV_OBJ_FLAG_HIDDEN);                   /* ������Ϣ�� */
    }
}

static void lv_example_msgbox(void)
{
    static const char *btns[] = { " ", " ", "OK", "" };

    msgbox = lv_msgbox_create(lv_scr_act(),LV_SYMBOL_WARNING "Notice","Excessive volume may damage hearing.",btns,false);
    lv_obj_set_size(msgbox,300,170);
    lv_obj_center(msgbox);
    lv_obj_set_style_border_width(msgbox,0,LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(msgbox,20,LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(msgbox,lv_color_hex(0xa9a9a9), LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(msgbox,18,LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(msgbox,20,LV_STATE_DEFAULT);
    lv_obj_add_event_cb(msgbox, msgbox_event_cb, LV_EVENT_VALUE_CHANGED, NULL);              /* ����¼� */

        /* ��Ϣ����� */
    lv_obj_t *title = lv_msgbox_get_title(msgbox);                                           /* ��ȡ���ⲿ�� */
    lv_obj_set_style_text_font(title, &lv_font_montserrat_20, LV_STATE_DEFAULT);             /* �������� */
    lv_obj_set_style_text_color(title, lv_color_hex(0xff0000),LV_STATE_DEFAULT);             /* �����ı���ɫ����ɫ */

        /* ��Ϣ������ */
    lv_obj_t *content = lv_msgbox_get_content(msgbox);                                       /* ��ȡ���岿�� */
    lv_obj_set_style_text_font(content, &lv_font_montserrat_20, LV_STATE_DEFAULT);           /* �������� */
    lv_obj_set_style_text_color(content, lv_color_hex(0x6c6c6c), LV_STATE_DEFAULT);          /* �����ı���ɫ����ɫ */
    lv_obj_set_style_pad_top(content,15,LV_STATE_DEFAULT);                                   /* ���ö������ */

        /* ��Ϣ��ť */
    lv_obj_t *btn = lv_msgbox_get_btns(msgbox);                                              /* ��ȡ��ť���󲿷� */
    lv_obj_set_style_bg_opa(btn, 0, LV_PART_ITEMS);                                          /* ���ð�ť����͸���� */
    lv_obj_set_style_shadow_width(btn, 0, LV_PART_ITEMS);                                    /* ȥ����ť��Ӱ */
    lv_obj_set_style_text_font(btn, &lv_font_montserrat_20, LV_PART_ITEMS);                  /* �������� */
    lv_obj_set_style_text_color(btn, lv_color_hex(0x2271df),LV_PART_ITEMS);                  /* �����ı���ɫ��δ���£�����ɫ */
    lv_obj_set_style_text_color(btn, lv_color_hex(0xff0000),LV_PART_ITEMS|LV_STATE_PRESSED); /* �����ı���ɫ���Ѱ��£�����ɫ */

    lv_obj_add_flag(msgbox, LV_OBJ_FLAG_HIDDEN);                                             /* ������Ϣ�� */

}


/**
 * @brief  LVGL��ʾ
 * @param  ��
 * @return ��
 */
void lv_mainstart(void)
{
    lv_example_slider();
    lv_example_msgbox();
}
