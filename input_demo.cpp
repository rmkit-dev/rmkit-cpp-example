#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define STB_TRUETYPE_IMPLEMENTATION

#include <iostream>
#include <cstddef>

#include "second.h"
#include "rmkit.h"
using namespace std;

class App {
  public:
  ui::Scene demo_scene;


  App() {
    demo_scene = ui::make_scene();
    ui::MainLoop::set_scene(demo_scene);

    auto fb = framebuffer::get();
    fb->clear_screen();
    fb->redraw_screen();
    auto structuredArgs_0 = fb->get_display_size();    auto w = get<0>(structuredArgs_0);    auto h = get<1>(structuredArgs_0);



    auto v_layout = ui::VerticalLayout(0, 0, w, h, demo_scene);
    auto h_layout1 = ui::HorizontalLayout(0, 0, w, 50, demo_scene);
    auto h_layout2 = ui::HorizontalLayout(0, 0, w, 50, demo_scene);
    auto h_layout3 = ui::HorizontalLayout(0, 0, w, 50, demo_scene);

    v_layout.pack_start(h_layout1);
    v_layout.pack_start(h_layout2);
    v_layout.pack_start(h_layout3);

    h_layout1.pack_start(new ui::Text(0, 0, 200, 50, "Héllo world"));
    h_layout2.pack_center(new ui::Text(0, 0, 200, 50, "Hello world"));
    h_layout3.pack_end(new ui::Text(0, 0, 200, 50, "Hello world"));

    auto h_layout = ui::HorizontalLayout(0, 0, w, h, demo_scene);

    v_layout.pack_start(h_layout);

    h_layout.pack_center(new ui::TextInput(0, 50, 1000, 50));

    auto range = new ui::RangeInput(0, 150, 1000, 50);
    range->set_range(0, 100);
    h_layout.pack_center(range); }



  auto handle_key_event(input::SynKeyEvent &key_ev) {
    std::cerr << "KEY PRESSED" << ' ' << key_ev.key << std::endl; }

  auto handle_motion_event(input::SynMotionEvent &syn_ev) {
    (void)0; }

  auto run() {

    ui::MainLoop::key_event += PLS_DELEGATE(this->handle_key_event);
    ui::MainLoop::motion_event += PLS_DELEGATE(this->handle_motion_event);


    ui::MainLoop::refresh();
    ui::MainLoop::redraw();
    while (true) {
      ui::MainLoop::main();
      ui::MainLoop::redraw();
      ui::MainLoop::read_input(); } } };


int main() {
  App app;
  Secondary::exported();
  app.run(); };
