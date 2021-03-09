#include "main.h"
#include "devices.h"

void outakeControl(const std::int32_t velocity) {
  leftUpwards.move_velocity(-velocity);
  rightUpwards.move_velocity(-velocity);
}

void outakeStop() {
  leftUpwards.move_velocity(0);
  rightUpwards.move_velocity(0);
}
