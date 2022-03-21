//
// Created by User on 19.03.2022.
//

#include "CloseEventFilterMTV.h"
#include <QEvent>
#include "notepadMTV.h"
bool isWarned = false;
bool CloseEventFilterMTV::eventFilter(QObject *obj, QEvent *event) {
    if(event->type() == QEvent::Close && !isWarned){
        event->ignore();
        Notepad* sender = (Notepad*) obj;
        isWarned = true;
        sender->beforeClosing(true);
        return true;
    }
    return false;
}

