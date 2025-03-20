#include "lvgl/lvgl.h"
#include <stdio.h>

/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())


static const lv_font_t* font;       /* �������� */

lv_obj_t * TX15_tileview;
lv_obj_t *tile_1;
lv_obj_t *tile_2;
lv_obj_t *tile_3;
lv_obj_t *tile_4;

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

static void tileview_page1(void)
{
    tile_1 = lv_tileview_add_tile( TX15_tileview, 0, 0, LV_DIR_RIGHT );                /* ���ҳ��1 */
    /* ����ҳ������ */
    lv_obj_t *label_1 = lv_label_create(tile_1);                                            /* ������ǩ */
    lv_label_set_text(label_1, "button & switch  1/4");                                                   /* �����ı����� */
    lv_obj_set_style_text_font(label_1, font, LV_STATE_DEFAULT);                            /* �������� */
    lv_obj_center(label_1);                                                                 /* ����λ�� */
    //lv_obj_align_to(tile_1, tile_1,LV_ALIGN_TOP_RIGHT, 200, 20);                                    /* ����λ�� */
}

static void tileview_page2(void)
{
        tile_2 = lv_tileview_add_tile( TX15_tileview, 1, 0, LV_DIR_LEFT|LV_DIR_RIGHT );    /* ���ҳ��2 */
    lv_obj_t *label_2 = lv_label_create(tile_2);                                            /* ������ǩ */
    lv_label_set_text(label_2, "analogo 2/4");                                                   /* �����ı����� */
    lv_obj_set_style_text_font(label_2, font, LV_STATE_DEFAULT);                            /* �������� */
    lv_obj_center(label_2);                                                                 /* ����λ�� */
}
static void tileview_page3(void)
{
        tile_3 = lv_tileview_add_tile( TX15_tileview, 2, 0, LV_DIR_LEFT|LV_DIR_RIGHT );    /* ���ҳ��3 */
            lv_obj_t *label_3 = lv_label_create(tile_3);                                            /* ������ǩ */
    lv_label_set_text(label_3, "Contronl    3/4");                                                   /* �����ı����� */
    lv_obj_set_style_text_font(label_3, font, LV_STATE_DEFAULT);                            /* �������� */
    lv_obj_center(label_3);                                                                 /* ����λ�� */
}

static void tileview_page4(void)
{
    tile_4 = lv_tileview_add_tile( TX15_tileview, 3, 0, LV_DIR_LEFT );                 /* ���ҳ��4 */

    lv_obj_t *label_4 = lv_label_create(tile_4);                                            /* ������ǩ */
    lv_label_set_text(label_4, "MP3 Player 4/4");                                                   /* �����ı����� */
    lv_obj_set_style_text_font(label_4, font, LV_STATE_DEFAULT);                            /* �������� */
    lv_obj_center(label_4);

            /* ���� */
    lv_obj_t * slider = lv_slider_create(tile_4);                             /* �������� */
    lv_obj_set_size(slider, scr_act_width() / 3, 10);                               /* ���ô�С */
    lv_obj_align(slider,LV_ALIGN_TOP_MID, 0, 200);                                                          /* ����λ�� */
    lv_slider_set_value(slider, 50, LV_ANIM_OFF);                                   /* ���õ�ǰֵ */
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);     /* ����¼� */

    /* �ٷֱȱ�ǩ */
    slider_label = lv_label_create(tile_4);                                   /* �����ٷֱȱ�ǩ */
    lv_label_set_text(slider_label, "50%");                                         /* �����ı����� */
    lv_obj_set_style_text_font(slider_label, font, LV_STATE_DEFAULT);               /* �������� */
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_RIGHT_MID, 20, 0);           /* ����λ�� */

        /* ����ͼ�� */
    lv_obj_t *sound_label = lv_label_create(tile_4);                          /* ����������ǩ */
    lv_label_set_text(sound_label, LV_SYMBOL_VOLUME_MAX);                           /* �����ı����ݣ�����ͼ�� */
    lv_obj_set_style_text_font(sound_label, font, LV_STATE_DEFAULT);                /* �������� */
    lv_obj_align_to(sound_label, slider, LV_ALIGN_OUT_LEFT_MID, -20, 0);            /* ����λ�� */
                                                                    /* ����λ�� */
}

static void lv_example_tileview(void)
{
    /* ������Ļ����������� */
        font = &lv_font_montserrat_14;


    /* ����ƽ����ͼҳ�� */
    TX15_tileview = lv_tileview_create(lv_scr_act());                                  /* ����ƽ����ͼ */
    tileview_page1();
    tileview_page2();
    tileview_page3();
    tileview_page4();
    //lv_obj_remove_style(TX15_tileview, NULL, LV_PART_SCROLLBAR);                                 /* �Ƴ������� */

    /* ���״̬�� */
    lv_obj_t *label_left = lv_label_create(lv_scr_act());                                   /* ������ǩ */
    lv_label_set_text(label_left, "AM 9:30" );                                              /* �����ı����� */
    lv_obj_set_style_text_font(label_left, font, LV_STATE_DEFAULT);                         /* �������� */
    lv_obj_align(label_left, LV_ALIGN_TOP_LEFT, 10, 10);                                    /* ����λ�� */

    /* �Ҳ�״̬�� */
    lv_obj_t *label_right = lv_label_create(lv_scr_act());                                  /* ������ǩ */
    lv_label_set_text(label_right, "   70% " LV_SYMBOL_BATTERY_3);           /* �����ı����� */
    lv_obj_set_style_text_font(label_right, font, LV_STATE_DEFAULT);                        /* �������� */
    lv_obj_align(label_right, LV_ALIGN_TOP_RIGHT, -10, 10);                                 /* ����λ�� */
}

/**
 * @brief  LVGL��ʾ
 * @param  ��
 * @return ��
 */
void lv_mainstart(void)
{
    lv_example_tileview();
}
