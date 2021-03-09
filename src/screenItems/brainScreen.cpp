#include "main.h"
#include "devices.h"

// variables
int customTimer = 0;
int customTimerStart = 0;
double drivetrainTemp = 0;
double batteryCapacity = 0;
double customTimerArc = 0;

lv_obj_t * myLabel;



static lv_res_t btn_click_action(lv_obj_t * btn)
{
uint8_t id = lv_obj_get_free_num(btn);
if(id == 1)
{
isSkills = true;

}
/* The button is released.
* Make something here */
return LV_RES_OK; /*Return OK if the button is not deleted*/
}





int brainScreen() {
// things that only need to be ran once
/*Create a Tab view object*/
lv_obj_t *tabview;
tabview = lv_tabview_create(lv_scr_act(), NULL);

/*Add 3 tabs (the tabs are page (lv_page) and can be scrolled*/
lv_obj_t *tab1 = lv_tabview_add_tab(tabview, "Overview");
lv_obj_t *tab2 = lv_tabview_add_tab(tabview, "Autonomous");
lv_obj_t *tab3 = lv_tabview_add_tab(tabview, "Diagnostics");

/*Add content to the tabs*/
lv_obj_t * label69420 = lv_label_create(tab1, NULL);
lv_label_set_text(label69420, "This the first tab\n\n"
                         "If the content\n"
                         "of a tab\n"
                         "become too long\n"
                         "then it \n"
                         "automatically\n"
                         "become\n"
                         "scrollable.");

label69420 = lv_label_create(tab2, NULL);
lv_label_set_text(label69420, "Second tab");

label69420 = lv_label_create(tab3, NULL);
lv_label_set_text(label69420, "Third tab");


  /*Create a line meter */
  lv_obj_t * lmeter;
  lmeter = lv_lmeter_create(tab1, NULL);

  lv_lmeter_set_range(lmeter, 0, 100);                   /*Set the range*/
  lv_lmeter_set_scale(lmeter, 180, 21);                  /*Set the angle and number of lines*/
  lv_obj_set_size(lmeter, 150, 150);
  lv_obj_align(lmeter, NULL, LV_ALIGN_IN_LEFT_MID, 0, 0);

  /*Describe the color for the needles*/
  static lv_color_t needle_colors[0];
  needle_colors[0] = LV_COLOR_RED;


  /*Create a gauge*/
  lv_obj_t * gauge1 = lv_gauge_create(tab1, NULL);
  lv_gauge_set_needle_count(gauge1, 1, needle_colors);
  lv_obj_set_size(gauge1, 200, 200);
  lv_obj_align(gauge1, NULL, LV_ALIGN_CENTER, 0, 0);


  /*Create an Arc*/
  lv_obj_t * arc = lv_arc_create(tab1, NULL);
  lv_obj_align(arc, NULL, LV_ALIGN_IN_RIGHT_MID, 0, 0);

  // labels
  lv_obj_t * label;
  label = lv_label_create(lmeter, NULL);
  lv_label_set_style(label, &lv_style_pretty);
  lv_obj_align(label, NULL, LV_ALIGN_IN_LEFT_MID, 0, 0);




  while (true) {
    drivetrainTemp = (leftMotorA.get_temperature() + leftMotorB.get_temperature() + rightMotorA.get_temperature() + rightMotorB.get_temperature())/4;
    batteryCapacity = pros::battery::get_capacity();
    customTimerArc = (customTimer/customTimerStart)*360;

    lv_lmeter_set_value(lmeter, batteryCapacity);
    lv_gauge_set_value(gauge1, 0, drivetrainTemp);
    lv_arc_set_angles(arc, 0, customTimerArc);
    lv_label_set_array_text(label, "%d%%", batteryCapacity);





    lv_obj_t * label = lv_label_create(tab2, NULL);
    lv_label_set_text(label, "Default buttons");
    lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 5);
    /*Create a normal button*/
    lv_obj_t * btn1 = lv_btn_create(tab2, NULL);
    lv_cont_set_fit(btn1, true, true); /*Enable resizing horizontally and vertically*/
    lv_obj_align(btn1, label, LV_ALIGN_OUT_BOTTOM_MID, 0, 10);
    lv_btn_set_state(btn1, LV_BTN_STATE_TGL_REL);
    lv_obj_set_free_num(btn1, 1); /*Set a unique number for the button*/
    lv_btn_set_action(btn1, LV_BTN_ACTION_CLICK, btn_click_action);
    /*Add a label to the button*/
    label = lv_label_create(btn1, NULL);
    lv_label_set_text(label, "Toggled");






    pros::delay(20);
  }
  return 0;
}

int customTimerWorker() {
  if (customTimer > 0) {
    customTimer--;
    pros::delay(1000);
  }
  if (customTimer == 16) {
    controllerShake();
  }
  return 0;
}
