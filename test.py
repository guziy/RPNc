from ctypes import c_char_p
from ctypes import *
dll = CDLL('rmnlib.so')

dll.get_message.restype = c_char_p # c_char_p is a pointer to a string
print dll.get_message()
print dll.get_number()

rpn_file_path = c_char_p()
rpn_file_path.value = 'data/dp2002050100_00000045p'
file_unit = c_int(1)
options = c_char_p()
options.value = 'STD+RND'
dummy = c_int(0)
print dll.fnom_wrapper(file_unit, rpn_file_path, options, dummy)
options.value = 'RND'
print dll.fstouv_wrapper(file_unit, options)

