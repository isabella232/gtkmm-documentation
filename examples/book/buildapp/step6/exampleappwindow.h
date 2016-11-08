/* gtkmm example Copyright (C) 2016 gtkmm development team
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
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GTKMM_EXAMPLEAPPWINDOW_H_
#define GTKMM_EXAMPLEAPPWINDOW_H_

#include <gtkmm.h>

class ExampleAppWindow : public Gtk::ApplicationWindow
{
public:
  ExampleAppWindow(BaseObjectType* cobject,
    const Glib::RefPtr<Gtk::Builder>& refBuilder);

  static ExampleAppWindow* create();

  void open_file_view(const Glib::RefPtr<Gio::File>& file);

protected:
  // Signal handlers
  void on_search_text_changed();
  void on_visible_child_changed();

  Glib::RefPtr<Gtk::Builder> m_refBuilder;
  Glib::RefPtr<Gio::Settings> m_settings;
  Gtk::Stack* m_stack;
  Gtk::ToggleButton* m_search;
  Gtk::SearchBar* m_searchbar;
  Gtk::SearchEntry* m_searchentry;
  Glib::RefPtr<Glib::Binding> m_prop_binding;
};

#endif /* GTKMM_EXAMPLEAPPWINDOW_H */