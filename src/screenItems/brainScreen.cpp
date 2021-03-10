#include "main.h"
#include "devices.h"

// stupid objects
lv_obj_t * arc = lv_arc_create(lv_scr_act(), NULL);

void btnSetToggled(lv_obj_t * btn, bool toggled)
{
    if(toggled != (lv_btn_get_state(btn) >= 2)) lv_btn_toggle(btn);
}


// variables
int customTimer = 60;
double dummy = 0;
int customTimerStart = 0;
double drivetrainTemp = 0;
double batteryCapacity = 0;
double customTimerArc = 0;
bool button1Toggle = false;
bool button2Toggle = false;
bool startRight = false;


lv_obj_t * myButton;
lv_obj_t * myButton2;
lv_obj_t * myButtonLabel;
lv_obj_t * myButtonLabel2;
lv_obj_t * myLabel;
lv_obj_t * myLabel2;

lv_style_t myButtonStyleREL; //relesed style
lv_style_t myButtonStylePR; //pressed style

int customTimerWorker() {
  while(true) {
    if(customTimer > 0) {
      std::cout << customTimer << std::endl;
      customTimer--;
      pros::delay(1000);
    }
    if(customTimer == 15) {
      controllerShake();
    } else {
      dummy += 0.000001;
    }
  }
  return 0;
}

int arcUpdater() {
  while(true) {
    lv_obj_del(arc);
    lv_obj_t * arc = lv_arc_create(lv_scr_act(), NULL);
    lv_arc_set_angles(arc, 0, customTimer);
    lv_obj_align(arc, NULL, LV_ALIGN_CENTER, 0, 0);
    pros::delay(500);
  }

  return 0;
}

int lmeterUpdater() {
  while(true) {
    /*Create a simple style with ticker line width*/
    static lv_style_t style_lmeter1;
    lv_style_copy(&style_lmeter1, &lv_style_pretty_color);
    style_lmeter1.line.width = 2;
    style_lmeter1.line.color = LV_COLOR_SILVER;
    style_lmeter1.body.main_color = LV_COLOR_HEX(0x91bfed); /*Light blue*/
    style_lmeter1.body.grad_color = LV_COLOR_HEX(0x04386c); /*Dark blue*/
    /*Create the first line meter */
    lv_obj_t * lmeter;
    lmeter = lv_lmeter_create(lv_scr_act(), NULL);
    lv_lmeter_set_range(lmeter, 0, 100); /*Set the range*/
    lv_lmeter_set_value(lmeter, pros::battery::get_capacity()); /*Set the current value*/
    lv_lmeter_set_style(lmeter, &style_lmeter1); /*Apply the new style*/
    lv_obj_set_size(lmeter, 80, 80);
    lv_obj_align(lmeter, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 20, -20);
    /*Add a label to show the current value*/
    lv_obj_t * label;
    label = lv_label_create(lmeter, NULL);
    lv_label_set_array_text(label, "30%d", pros::battery::get_capacity());
    lv_label_set_style(label, &lv_style_pretty);
    lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
    pros::delay(500);
    lv_obj_del(lmeter);
  }
  return 0;
}


static lv_res_t btn_click_action(lv_obj_t * btn)
{
    uint8_t id = lv_obj_get_free_num(btn); //id usefull when there are multiple buttons

    if(id == 0)
    {

    button1Toggle = !button1Toggle;

    if (button1Toggle == false) {
      lv_btn_set_state(myButton, LV_BTN_STATE_TGL_PR);
      lv_label_set_text(myButtonLabel, "comp");
      isSkills = false;
    } else {
      lv_btn_set_state(myButton, LV_BTN_STATE_TGL_REL);
      lv_label_set_text(myButtonLabel, "skills");
      isSkills = true;
    }

    if (button2Toggle == false) {
      lv_btn_set_state(myButton2, LV_BTN_STATE_TGL_PR);
      lv_label_set_text(myButtonLabel2, "left");
      startRight = false;
    } else {
      lv_btn_set_state(myButton2, LV_BTN_STATE_TGL_REL);
      lv_label_set_text(myButtonLabel2, "right");
      startRight = true;
    }
    }


    return LV_RES_OK;
}

static lv_res_t tabWorker(lv_obj_t * btn) {

}

void testDisplay() {

  // make an lmeter
  pros::Task lmeterCreator(lmeterUpdater);

  // create an arc
  pros::Task arcCreator(arcUpdater);


  myButton = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
  lv_obj_set_free_num(myButton, 0); //set button is to 0
  lv_btn_set_action(myButton, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
  lv_obj_align(myButton, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0); //set the position to top mid

  myButtonLabel = lv_label_create(myButton, NULL); //create label and puts it inside of the button
  lv_label_set_text(myButtonLabel, "skills");


  myButton2 = lv_btn_create(lv_scr_act(), NULL); //create button, lv_scr_act() is deafult screen object
  lv_obj_set_free_num(myButton, 0); //set button is to 0
  lv_btn_set_action(myButton, LV_BTN_ACTION_CLICK, btn_click_action); //set function to be called on button click
  lv_obj_align(myButton, NULL, LV_ALIGN_IN_TOP_MID, 0, 0); //set the position to top mid

  myButtonLabel2 = lv_label_create(myButton2, NULL); //create label and puts it inside of the button
  lv_label_set_text(myButtonLabel2, "left");


}



int brainScreen() {

  while (true) {
    double batteryCapacityArc = pros::battery::get_capacity();

    pros::delay(20);
  }
  return 0;
}
