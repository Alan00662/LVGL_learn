#include "lvgl/lvgl.h"
#include <stdio.h>

/* ��ȡ��ǰ���Ļ�Ŀ�� */
#define scr_act_width() lv_obj_get_width(lv_scr_act())
#define scr_act_height() lv_obj_get_height(lv_scr_act())

/* ����ͼƬ���������鲿�� */
static lv_obj_t *img;
static lv_obj_t *slider_zoom, *slider_angle, *slider_r, *slider_g, *slider_b, *slider_opa;

LV_IMG_DECLARE(img_user);                           /* ����ͼƬ */

static void slider_event_cb(lv_event_t *e)
{
    lv_img_set_zoom(img, lv_slider_get_value(slider_zoom));                                         /* ����ͼƬ���� */
    lv_img_set_angle(img, lv_slider_get_value(slider_angle));                                       /* ����ͼƬ��ת�Ƕ� */

    /* ����ͼƬ������ɫ */
    lv_obj_set_style_img_recolor(img,
                                 lv_color_make(lv_slider_get_value(slider_r), lv_slider_get_value(slider_g), lv_slider_get_value(slider_b)),
                                 LV_PART_MAIN);

    lv_obj_set_style_img_recolor_opa(img, lv_slider_get_value(slider_opa), LV_PART_MAIN);           /* ����������ɫ͸���� */
}

static lv_obj_t *my_slider_create(lv_color_t color)
{
    lv_obj_t *slider = lv_slider_create(lv_scr_act());                                              /* �������� */
    lv_obj_set_height(slider, scr_act_height() / 20);                                               /* ���ø߶� */
    lv_obj_set_width(slider, scr_act_width() / 3);                                                  /* ���ÿ�� */
    lv_obj_remove_style(slider, NULL, LV_PART_KNOB);                                                /* �Ƴ���ť */
    lv_obj_set_style_bg_color(slider,color,LV_PART_INDICATOR);                                      /* ���û���ָʾ����ɫ */
    lv_obj_set_style_bg_color(slider,lv_color_darken(color, 100),LV_PART_MAIN);                     /* ���û���������ɫ��͸���� */
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, NULL);                     /* ���û���ص� */
    return slider;
}

static void lv_example_img(void)
{
    img = lv_img_create(lv_scr_act());
    lv_img_set_src(img, &img_user);
    lv_obj_align(img, LV_ALIGN_CENTER, -scr_act_width() / 5, 0);                                    /* ����ͼƬλ�� */
    lv_obj_update_layout(img);
        /* ͼƬ���ſ��ƻ��� */
    slider_zoom = my_slider_create(lv_color_hex(0x989c98));                                         /* �������� */
    lv_slider_set_range(slider_zoom, 128, 512);                                                     /* ���û���ķ�Χ */
    lv_slider_set_value(slider_zoom, 256, LV_ANIM_OFF);                                             /* ���û����ֵ */
    lv_obj_align(slider_zoom, LV_ALIGN_CENTER, scr_act_width() / 4, -scr_act_height() / 4);         /* ���û���λ�� */

        /* ��ת�Ƕȿ��ƻ��� */
    slider_angle = my_slider_create(lv_color_hex(0x989c98));                                        /* �������� */
    lv_slider_set_range(slider_angle, 0, 3600);                                                     /* ���û���ķ�Χ */
    lv_obj_align_to(slider_angle, slider_zoom, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 20); /* ���û���λ�� */
        /* ��ɫͨ�����ƻ��� */
    slider_r = my_slider_create(lv_color_hex(0xff0000));                                            /* �������� */
    lv_slider_set_range(slider_r, 0, 255);                                                          /* ���û���ķ�Χ */
    lv_obj_align_to(slider_r, slider_angle, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 20);    /* ���û���λ�� */

        /* ��ɫͨ�����ƻ��� */
    slider_g = my_slider_create(lv_color_hex(0x00ff00));                                            /* �������� */
    lv_slider_set_range(slider_g, 0, 255);                                                          /* ���û���ķ�Χ */
    lv_obj_align_to(slider_g, slider_r, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 20);        /* ���û���λ�� */

    /* ��ɫͨ�����ƻ��� */
    slider_b = my_slider_create(lv_color_hex(0x0000ff));                                            /* �������� */
    lv_slider_set_range(slider_b, 0, 255);                                                          /* ���û���ķ�Χ */
    lv_obj_align_to(slider_b, slider_g, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 20);        /* ���û���λ�� */

        /* ��ɫ͸���ȿ��ƻ��� */
    slider_opa = my_slider_create(lv_color_hex(0x000000));                                          /* �������� */
    lv_slider_set_range(slider_opa, 0, 255);                                                        /* ���û���ķ�Χ */
    lv_slider_set_value(slider_opa, 150, LV_ANIM_OFF);                                              /* ���û����ֵ */
    lv_obj_align_to(slider_opa, slider_b, LV_ALIGN_OUT_BOTTOM_LEFT, 0, scr_act_height() / 20);      /* ���û���λ�� */                                                              /* ����ͼƬ���� */
}

/**
 * @brief  LVGL��ʾ
 * @param  ��
 * @return ��
 */
void lv_mainstart(void)
{
    lv_example_img();

}
