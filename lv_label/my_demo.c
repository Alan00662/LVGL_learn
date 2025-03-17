#include "lvgl/lvgl.h"
#include <stdio.h>

/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())

#if (1 != LV_FONT_MONTSERRAT_10 || 1 != LV_FONT_MONTSERRAT_14 || 1 != LV_FONT_MONTSERRAT_20)
    #error Please Make Sure Enable LV_FONT_MONTSERRAT_10 & LV_FONT_MONTSERRAT_14 & LV_FONT_MONTSERRAT_20
#endif

static const lv_font_t *font;

/**
 * @brief  ��1
 * @param  ��
 * @return ��
 */
static void lv_example_label_1(void)
{
    if (scr_act_width() <= 320)
        font = &lv_font_montserrat_10;
    else if (scr_act_width() <= 480)
        font = &lv_font_montserrat_14;
    else
        font = &lv_font_montserrat_20;

    lv_obj_t* label = lv_label_create(lv_scr_act());                                /* ���岢������ǩ */
    lv_label_set_text(label, "#0000ff Re-color# #ff00ff words# #ff0000 of a# "      /* ���ñ�ǩ�ı� */
                             "label, align the lines to the center"
                             "and  wrap long text automatically.");
    lv_label_set_recolor(label, true);                                              /* ���ñ�ǩ�ı�������ɫ */
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN);                          /* ���ñ�ǩ�ı����� */
    lv_obj_set_width(label, scr_act_width() / 3);                                   /* ���ñ�ǩ��� */
    lv_obj_align(label, LV_ALIGN_CENTER, -scr_act_width() / 3, 0);                  /* ���ñ�ǩλ�� */
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);         /* ���ñ�ǩ�ı����뷽ʽ */
}

/**
 * @brief  ��2
 * @param  ��
 * @return ��
 */
static void lv_example_label_2(void)
{
    lv_obj_t* label = lv_label_create(lv_scr_act());                                /* ���岢������ǩ */
    lv_label_set_text(label, "It is a circularly scrolling text. ");                /* ���ñ�ǩ�ı� */
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN);                          /* ���ñ�ǩ�ı����� */
    lv_obj_set_width(label, scr_act_width() / 3);                                   /* ���ñ�ǩ��� */
    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);                   /* ���ñ�ǩ��ģʽ��ѭ������ */
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);                                     /* ���ñ�ǩλ�� */
}

static void lv_example_label_3(void)
{
    lv_obj_t* label = lv_label_create(lv_scr_act());                                /* ���岢������ǩ */
    lv_label_set_text_fmt(label, "Label can set text like %s", "printf");           /* ���ñ�ǩ�ı� */
    lv_obj_set_style_text_font(label, font, LV_PART_MAIN);                          /* ���ñ�ǩ�ı����� */
    lv_obj_set_width(label, scr_act_width() / 3);                                   /* ���ñ�ǩ��� */
    lv_obj_align(label, LV_ALIGN_CENTER, scr_act_width() / 3, 0);                   /* ���ñ�ǩλ�� */
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);         /* ���ñ�ǩ�ı����뷽ʽ */

    lv_obj_t* label_shadow = lv_label_create(lv_scr_act());                         /* ���岢������Ӱ��ǩ */
    lv_label_set_text(label_shadow, lv_label_get_text(label));                      /* ���ñ�ǩ�ı� */
    lv_obj_set_style_text_font(label_shadow, font, LV_PART_MAIN);                   /* ���ñ�ǩ�ı����� */
    lv_obj_set_width(label_shadow, scr_act_width() / 3);                            /* ���ñ�ǩ��� */
    lv_obj_set_style_text_opa(label_shadow, LV_OPA_30, LV_PART_MAIN);               /* ���ñ�ǩ�ı�͸���� */
    lv_obj_set_style_text_color(label_shadow, lv_color_black(), LV_PART_MAIN);      /* ���ñ�ǩ�ı���ɫ */
    lv_obj_set_style_text_align(label_shadow, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN);  /* ���ñ�ǩ�ı����뷽ʽ */
    lv_obj_align_to(label_shadow, label, LV_ALIGN_TOP_LEFT, 3, 3);                  /* ���ñ�ǩλ�� */
}

/**
 * @brief  LVGL��ʾ
 * @param  ��
 * @return ��
 */
void lv_mainstart(void)
{
    lv_example_label_1();
    lv_example_label_2();
    lv_example_label_3();
}
