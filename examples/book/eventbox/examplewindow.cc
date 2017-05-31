/* gtkmm example Copyright (C) 2002 gtkmm development team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "examplewindow.h"

ExampleWindow::ExampleWindow()
: m_Label("Click here to quit, quit, quit, quit, quit")
{
  set_title ("EventBox");

  m_EventBox.set_margin(10);
  add(m_EventBox);

  m_EventBox.add(m_Label);

  //Clip the label short:
  set_default_size(110, 20);
  m_Label.set_size_request(110, 20);
  m_Label.set_ellipsize(Pango::EllipsizeMode::END);

  //And bind an action to it:
  m_EventBox.signal_button_press_event().connect(
    sigc::mem_fun(*this, &ExampleWindow::on_eventbox_button_press), false);

  m_EventBox.set_tooltip_text("Click me!");
}

ExampleWindow::~ExampleWindow()
{
}

bool ExampleWindow::on_eventbox_button_press(Gdk::EventButton&)
{
  hide();
  return true;
}
