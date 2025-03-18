#include "lvgl/lvgl.h"
#include <stdio.h>

/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())


static const lv_font_t* font;       /* �������� */

static lv_obj_t *keyboard;          /* ���� */
static lv_obj_t *label_name;        /* �û���������ʾ��ǩ */
static lv_obj_t *label_pass;        /* ����������ʾ��ǩ */

static void name_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);            /* ��ȡ�¼����� */
    lv_obj_t *target = lv_event_get_target(e);              /* ��ȡ����Դ */

    if(code == LV_EVENT_FOCUSED)                            /* �¼����ͣ����۽� */
    {
        lv_keyboard_set_textarea(keyboard, target);         /* �����û����ı���ͼ��� */
    }
    else if(code == LV_EVENT_VALUE_CHANGED)                 /* �¼����ͣ��ı�������ݷ����仯 */
    {
        const char *txt = lv_textarea_get_text(target);     /* ��ȡ�ı�����ı� */

        if(strcmp(txt,"admin") == 0)                        /* �ж��û����Ƿ���ȷ */
        {
            lv_label_set_text(label_name, LV_SYMBOL_OK);    /* �û�����ȷ����ʾ�� */
        }
        else
        {
            lv_label_set_text(label_name, "");              /* �û������󣬲���ʾ */
        }
    }
}


static void password_event_cb(lv_event_t* e)
{
    lv_event_code_t code = lv_event_get_code(e);            /* ��ȡ�¼����� */
    lv_obj_t *target = lv_event_get_target(e);              /* ��ȡ����Դ */

    if(code == LV_EVENT_FOCUSED)                            /* �¼����ͣ����۽� */
    {
        lv_keyboard_set_textarea(keyboard, target);         /* �����û����ı���ͼ��� */
    }
    else if(code == LV_EVENT_VALUE_CHANGED)                 /* �¼����ͣ��ı�������ݷ����仯 */
    {
        const char *txt = lv_textarea_get_text(target);     /* ��ȡ�ı�����ı� */

        if(strcmp(txt,"123456") == 0)                       /* �ж������Ƿ���ȷ */
        {
            lv_label_set_text(label_pass, LV_SYMBOL_OK);    /* ������ȷ����ʾ�� */
        }
        else
        {
            lv_label_set_text(label_pass, "");              /* ������󣬲���ʾ */
        }
    }
}

static void lv_example_textarea(void)
{
    /* ������Ļ��С�������� */
    if (scr_act_width() <= 320)
    {
        font = &lv_font_montserrat_12;
    }
    else if (scr_act_width() <= 480)
    {
        font = &lv_font_montserrat_14;
    }
    else
    {
        font = &lv_font_montserrat_22;
    }

    /* �û����ı��� */
    lv_obj_t *textarea_name = lv_textarea_create(lv_scr_act());                                     /* �����ı��� */
    lv_obj_set_width(textarea_name, scr_act_width()/2);                                             /* ���ÿ�� */
    lv_obj_set_style_text_font(textarea_name, font, LV_PART_MAIN);                                  /* �������� */
    lv_obj_align(textarea_name, LV_ALIGN_CENTER, 0, -scr_act_height()/3 );                          /* ����λ�� */
    lv_textarea_set_one_line(textarea_name, true);                                                  /* ���õ���ģʽ */
    lv_textarea_set_max_length(textarea_name, 6);                                                   /* ���������ַ�����󳤶� */
    lv_textarea_set_placeholder_text(textarea_name, "user name");                                   /* ����ռλ�� */
    lv_obj_add_event_cb(textarea_name, name_event_cb, LV_EVENT_ALL, NULL);                          /* ����ı����¼��ص� */

    /* �û���������ʾ��ǩ */
    label_name = lv_label_create(lv_scr_act());                                                     /* ������ǩ */
    lv_label_set_text(label_name, "");                                                              /* Ĭ�ϲ���ʾ */
    lv_obj_set_style_text_font(label_name, font, LV_PART_MAIN);                                     /* �������� */
    lv_obj_align_to(label_name, textarea_name, LV_ALIGN_OUT_RIGHT_MID, 5, 0);                       /* ����λ�� */

    /* �����ı��� */
    lv_obj_t *textarea_pass = lv_textarea_create(lv_scr_act());                                     /* �����ı��� */
    lv_obj_set_width(textarea_pass, scr_act_width()/2);                                             /* ���ÿ�� */
    lv_obj_set_style_text_font(textarea_pass, font, LV_PART_MAIN);                                  /* �������� */
    lv_obj_align_to(textarea_pass, textarea_name, LV_ALIGN_OUT_BOTTOM_MID, 0, scr_act_height()/20); /* ����λ�� */
    lv_textarea_set_one_line(textarea_pass, true);                                                  /* ���õ���ģʽ */
    lv_textarea_set_password_mode(textarea_pass, true);                                             /* ��������ģʽ */
    lv_textarea_set_password_show_time(textarea_pass, 1000);                                        /* ����������ʾʱ�� */
    lv_textarea_set_max_length(textarea_pass, 8);                                                   /* ���������ַ�����󳤶� */
    lv_textarea_set_placeholder_text(textarea_pass, "password");                                    /* ����ռλ�� */
    lv_obj_add_event_cb(textarea_pass, password_event_cb, LV_EVENT_ALL, NULL);                          /* ����ı����¼��ص� */

    /* ����������ʾ��ǩ */
    label_pass = lv_label_create(lv_scr_act());                                                     /* ������ǩ */
    lv_label_set_text(label_pass, "");                                                              /* Ĭ�ϲ���ʾ */
    lv_obj_set_style_text_font(label_pass, font, LV_PART_MAIN);                                     /* �������� */
    lv_obj_align_to(label_pass, textarea_pass, LV_ALIGN_OUT_RIGHT_MID, 5, 0);                       /* ����λ�� */

    /* ���� */
    keyboard = lv_keyboard_create(lv_scr_act());                                                    /* �������� */
    lv_obj_set_size(keyboard, scr_act_width(), scr_act_height()/2);                                 /* ���ô�С */

}


/**
 * @brief  LVGL��ʾ
 * @param  ��
 * @return ��
 */
void lv_mainstart(void)
{

    lv_example_textarea();
}
