from ._anvil_designer import Form1Template
from anvil import *
import anvil.server

class Form1(Form1Template):
  def __init__(self, **properties):
    # Set Form properties and Data Bindings.
    self.init_components(**properties)

    # Any code you write here will run before the form opens.

  def button_1_click(self, **event_args):
        input_list = [int(x.strip()) for x in self.text_box_1.text.split()]
        sorted_list = anvil.server.call('selection_sort', input_list)
        self.text_box_2.text = ' '.join(map(str, sorted_list))
