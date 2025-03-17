#include "lvgl/lvgl.h"
#include <stdio.h>

/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())

static lv_obj_t *label;                                             /* ��ǰѡ���ǩ */
static const lv_font_t *dropdown_font;                              /* �������� */
static int16_t dropdown_width;                                      /* �б��� */

/* �����б��ѡ�� */
static const char *options =    "option 1\n"
                                "option 2\n"
                                "option 3\n"
                                "option 4\n"
                                "option 5\n"
                                "option 6\n"
                                "option 7\n"
                                "option 8\n";



/**
 * @brief  �����б��¼��ص�
 * @param  ��
 * @return ��
 */
static void dropdown_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);                    /* ��ȡ�¼����� */
    lv_obj_t *dropdown = lv_event_get_target(e);                    /* ��ȡ����Դ */

    if (LV_EVENT_VALUE_CHANGED == code)                             /* �ж��¼����� */
    {
        char buf[10];
        lv_dropdown_get_selected_str(dropdown, buf, sizeof(buf));   /* ��ȡ��ǰѡ���ı� */
        lv_label_set_text(label, buf);                              /* ��ʾ��ǰѡ���ı� */
    }
}


static void lv_example_dropdown_1(void)
{
    if (scr_act_width() <= 480)
    {
        dropdown_font = &lv_font_montserrat_18;
        dropdown_width = 120;
    }
    else
    {
        dropdown_font = &lv_font_montserrat_22;
        dropdown_width = 150;
    }

    lv_obj_t* dropdown = lv_dropdown_create(lv_scr_act());                                      /* ���岢���������б� */
    lv_dropdown_set_options_static(dropdown, options);                                          /* ��������б�ѡ�� */
    lv_obj_set_style_text_font(dropdown, dropdown_font, LV_PART_MAIN);                          /* ���������б����� */
    lv_obj_set_width(dropdown, dropdown_width);                                                 /* ���������б��� */
    lv_obj_align(dropdown, LV_ALIGN_CENTER, -scr_act_width() / 3, 0);                           /* ���������б�λ�� */

    label = lv_label_create(lv_scr_act());                                                      /* ���岢������ǩ */
    lv_obj_set_style_text_font(label, dropdown_font, LV_PART_MAIN);                             /* ���ñ�ǩ������ */
    lv_obj_set_width(label, dropdown_width);                                                    /* ���ñ�ǩ��� */
    lv_obj_align_to(label, dropdown, LV_ALIGN_OUT_TOP_MID, 15, -scr_act_height() / 8);          /* ���ñ�ǩλ�� */
    lv_label_set_text(label, "option 1");                                                       /* ���ñ�ǩ�ı� */

    lv_obj_add_event_cb(dropdown, dropdown_event_cb, LV_EVENT_VALUE_CHANGED, NULL);             /* ��������б�ص� */
}

static void lv_example_dropdown_2(void)
{
    lv_obj_t* dropdown;                                                                         /* ���������б� */

    dropdown = lv_dropdown_create(lv_scr_act());                                                /* ���������б� */
    lv_dropdown_set_options_static(dropdown, options);                                          /* ��������б�ѡ�� */
    lv_obj_set_style_text_font(dropdown, dropdown_font, LV_PART_MAIN);                          /* ���������б����� */
    lv_obj_set_width(dropdown, dropdown_width);                                                 /* ���������б��� */
    lv_dropdown_set_dir(dropdown, LV_DIR_BOTTOM);                                               /* ���������б��� */
    lv_dropdown_set_symbol(dropdown, LV_SYMBOL_DOWN);                                           /* ���������б���� */
    lv_obj_align(dropdown, LV_ALIGN_CENTER, scr_act_width() / 8, -3 * scr_act_height() / 8);    /* ���������б�λ�� */

    dropdown = lv_dropdown_create(lv_scr_act());                                                /* ���������б� */
    lv_dropdown_set_options_static(dropdown, options);                                          /* ��������б�ѡ�� */
    lv_obj_set_style_text_font(dropdown, dropdown_font, LV_PART_MAIN);                          /* ���������б����� */
    lv_obj_set_width(dropdown, dropdown_width);                                                 /* ���������б��� */
    lv_dropdown_set_dir(dropdown, LV_DIR_TOP);                                               /* ���������б��� */
    lv_dropdown_set_symbol(dropdown, LV_SYMBOL_UP);                                           /* ���������б���� */
    lv_obj_align(dropdown, LV_ALIGN_CENTER, scr_act_width() / 8, 3 * scr_act_height() / 8);    /* ���������б�λ�� */

    dropdown = lv_dropdown_create(lv_scr_act());                                                /* ���������б� */
    lv_dropdown_set_options_static(dropdown, options);                                          /* ��������б�ѡ�� */
    lv_obj_set_style_text_font(dropdown, dropdown_font, LV_PART_MAIN);                          /* ���������б����� */
    lv_obj_set_width(dropdown, dropdown_width);                                                 /* ���������б��� */
    lv_dropdown_set_dir(dropdown, LV_DIR_LEFT);                                               /* ���������б��� */
    lv_dropdown_set_symbol(dropdown, LV_SYMBOL_LEFT);                                           /* ���������б���� */
    lv_obj_align(dropdown, LV_ALIGN_CENTER, scr_act_width() / 8, -1 * scr_act_height() / 8);    /* ���������б�λ�� */

    dropdown = lv_dropdown_create(lv_scr_act());                                                /* ���������б� */
    lv_dropdown_set_options_static(dropdown, options);                                          /* ��������б�ѡ�� */
    lv_obj_set_style_text_font(dropdown, dropdown_font, LV_PART_MAIN);                          /* ���������б����� */
    lv_obj_set_width(dropdown, dropdown_width);                                                 /* ���������б��� */
    lv_dropdown_set_dir(dropdown, LV_DIR_RIGHT);                                               /* ���������б��� */
    lv_dropdown_set_symbol(dropdown, LV_SYMBOL_RIGHT);                                           /* ���������б���� */
    lv_obj_align(dropdown, LV_ALIGN_CENTER, scr_act_width() / 8, 1 * scr_act_height() / 8);    /* ���������б�λ�� */
}
/**
 * @brief  LVGL��ʾ
 * @param  ��
 * @return ��
 */
void lv_mainstart(void)
{
    lv_example_dropdown_1();
    lv_example_dropdown_2();
}
