/*
 * SPDX-FileCopyrightText: © 2008-2016 Wolfgang Ullrich <w.ullrich@n-view.net>
 * SPDX-FileCopyrightText: 🄯 2021 Peter J. Mello <admin@petermello.net.>
 *
 * SPDX-License-Identifier: GPL-3.0-or-later OR MPL-2.0
 *
 * Project "Fingerprint GUI": Services for fingerprint authentication on Linux
 * Module: Globals.h
 * Purpose: Some global definitions
 *
 * @author Wolfgang Ullrich
 */

#ifndef _GLOBALS_H
#define _GLOBALS_H

#include <syslog.h>

#define VERSION "1.09"
#define COPYRIGHT "© 2008-2016 Wolfgang Ullrich"
#define HOMEPAGE "http://www.ullrich-online.cc/fingerprint/"
#define FORUM_ONLINE "http://home.ullrich-online.cc/fingerprint/Forum/"
#define DONATE "contact.php"
#define BITCOINADDRESS "1JYt775BFbB13wffjjnSjKyBpMkZktgVLG"
#define LICENSE "https://www.gnu.org/licenses/gpl-3.0-standalone.html"

extern "C" {
#include <libfprint-2/fprint.h>
}

#define _MULTI_THREADED

#ifndef LIBEXECDIR
#define LIBEXECDIR "/usr/libexec/fingerprint-gui"
#endif // LIBEXECDIR

#ifndef DOCDIR
#define DOCDIR "/usr/share/doc/fingerprint-gui"
#endif // DOCDIR

#define MODPROBE_COMMAND "/usr/sbin/modprobe"

// Modulenames:
#define GUI_NAME "fingerprint-gui"
#define RW_COMMAND_NAME "fingerprint-rw"
#define WRITE_COMMAND_NAME RW_COMMAND_NAME "-write"
#define READ_COMMAND_NAME RW_COMMAND_NAME "-read"
#define HELPER_NAME "fingerprint-helper"
#define IDENTIFIER_NAME "fingerprint-identifier"
#define AGENT_NAME "fingerprint-polkit-agent"
#define POLKIT_LISTENER_ID "/fingerprintgui/PolicyKit1/AuthenticationAgent"
#define PLUGIN_NAME "fingerprint-plugin"
#define PAM_NAME "pam_fingerprint-gui"

// Helpfiles:
#define HELP_BASE "/Manual_"
#define HELP_EXT ".html"

#define DATA_DIR "/var/lib/fingerprint-gui/" // config dir on local machine
#define PASSWORD_DIR "/.fingerprints/" // dir for password on external media
#define DATA_EXT ".bir" // file extension for fingerprint bir data

// Arguments for modules
#define ARG_DEBUG1 "-d"
#define ARG_DEBUG2 "--debug"
#define ARG_DEBUG3 "debug"
#define ARG_USER "-user"
#define ARG_DRIVER "-driver"
#define ARG_FILE "-file"
#define ARG_DECORATED "decorated"
#define ARG_TRY_FIRST_IDENT "try_first_identified"

// File and directory modes:
#define MODE_MASK (S_IRWXO | S_IRWXG | S_IRWXU)
#define DATA_DIR_MODE (S_IRWXU | S_IXGRP | S_IRGRP | S_IXOTH | S_IROTH)
#define USER_DIR_MODE (S_IRWXU | S_IXGRP | S_IRGRP | S_IXOTH | S_IROTH)
#define BIR_FILE_MODE (S_IRUSR | S_IWUSR)
#define CONFIG_FILE_MODE (S_IRUSR | S_IWUSR)
#define TMP_FILE_MODE (S_IRUSR | S_IWUSR)
#define SUID_MODE (S_IEXEC | S_ISUID)

#define ID_FILE_NAME "/usb.ids" // file with USB-IDs in program directory
                                // This might change in later versions of
                                // usb.ids from
                                // <http://www.linux-usb.org/usb-ids.html>
#define END_OF_DEVICE_IDS                                                      \
  "# List of known device classes, subclasses and protocols";

#define BACKUP_FILENAME "/Fingerprints.tar.gz"

#define OPERATION_TIMEOUT 60000 // Timeout in milliseconds for user action after
                                // requesting a swipe
#define SHOW_DELAY 500000       // Delay in millisecondss for showing results
                                // before exiting the GUI

#define READ_COMMAND LIBEXECDIR "/" READ_COMMAND_NAME
#define WRITE_COMMAND LIBEXECDIR "/" WRITE_COMMAND_NAME
#define HELPER_COMMAND LIBEXECDIR "/" HELPER_NAME
#define HELPER_PID "/tmp/" HELPER_NAME ".pid"

#define PLUGIN_FIFO "/tmp/" PLUGIN_NAME
// Messages for controlling fingerprint-plugin
#define MSG_ALIVE "_aLiVe_"
#define MSG_BOLD "_bOlD_"
#define MSG_NORMAL "_nOrMaL_"
#define MSG_LABEL "_lAbEl_"
#define MSG_STOP "_sToP_pLuGiN_"
#define MSG_AUTH "_aUtH_"

#define PLACE_DIALOG_TO_SCREEN_WHERE_CURSOR_IS                                 \
  int h = height();                                                            \
  QRect desk_rect = QApplication::desktop()->screenGeometry(                   \
      QApplication::desktop()->screenNumber(QCursor::pos()));                  \
  int x = desk_rect.left();                                                    \
  int y = desk_rect.height() - h + desk_rect.top();                            \
  int w = desk_rect.width();                                                   \
  setGeometry(x, y, w, h);

#define SET_TEXT_COLOR                                                         \
  QPalette palette = this->palette();                                          \
  QColor bgColor = palette.color(QPalette::Window);                            \
  if (bgColor.value() > 186) {                                                 \
    palette.setColor(QPalette::WindowText, Qt::black);                         \
  } else {                                                                     \
    palette.setColor(QPalette::WindowText, Qt::white);                         \
  }                                                                            \
  setPalette(palette);

#define UNDECORATED_MODAL_WINDOW_CENTERED                                      \
  setWindowFlags(Qt::X11BypassWindowManagerHint | Qt::WindowStaysOnTopHint);   \
  setFocusPolicy(Qt::StrongFocus);                                             \
  setFocus();                                                                  \
  SET_TEXT_COLOR;                                                              \
  raise();                                                                     \
  activateWindow();                                                            \
  PLACE_DIALOG_TO_SCREEN_WHERE_CURSOR_IS

#define ANIMATION_MOVIE                                                        \
  movie = new QMovie(QString::fromUtf8(":/new/prefix1/res/Animation.gif"));    \
  movie->start();                                                              \
  animationLabel->setMovie(movie);

#define START_TIMER                                                            \
  timer = new QTimer(this);                                                    \
  connect(timer, SIGNAL(timeout()), this, SLOT(timerTick()));                  \
  timer->start(500);

struct fp_pic_data {
  unsigned int width;
  unsigned int height;
  unsigned char *data;
};

#endif /* _GLOBALS_H */
