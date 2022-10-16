# link the new servo library using cmake
add_library(TutorialServo STATIC)
target_sources(TutorialServo PRIVATE src/TutorialServo.cpp)
target_include_directories(TutorialServo PUBLIC include)
target_link_libraries(TutorialServo PRIVATE mbed-os)

# immitating cmake from tutorial servo pot control
add_executable(tutorial-servo-can-control) 
target_sources(tutorial-servo-can-control PRIVATE src/main.cpp)
# TODO: might have to add mbed-os below, swapped out for TutorialServo (might need both)
target_link_libraries(tutorial-servo-can-control PRIVATE 
    TutorialServo
    mbed-os
    CANMsg
)
mbed_set_post_build(tutorial-servo-can-control)

