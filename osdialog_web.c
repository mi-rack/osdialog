#include "osdialog.h"
#include <assert.h>
#include <emscripten.h>



int osdialog_message(osdialog_message_level level, osdialog_message_buttons buttons, const char *message) {
	if (buttons == OSDIALOG_OK)
		EM_ASM({
			alert(UTF8ToString($0));
		}, message);
	else
		return EM_ASM_INT({
			return confirm(UTF8ToString($0));
		}, message);
}


char *osdialog_file(osdialog_file_action action, const char *path, const char *filename, const char *filters) {
	return 0;
}


int osdialog_color_picker(osdialog_color *color, int opacity) {
	return 0;
}
