#include "consolewindow.h"






ConsoleWindow::ConsoleWindow(QWidget *parent) : QPlainTextEdit(parent)
{
    connect(this, SIGNAL(writeSignal()), this, SLOT(writeConsole()),Qt::BlockingQueuedConnection);
    connect(this, SIGNAL(readSignal()), this, SLOT(readConsole()), Qt::BlockingQueuedConnection);
    connect(this, SIGNAL(grabbedKey()), this, SLOT(clearStringBuff()));
     this->setReadOnly(true);
}



void ConsoleWindow::setId(int &_id){
    //id = _id;
}

void ConsoleWindow::writeConsole(){
    this->setReadOnly(false);
    QString input = QString::fromStdString (consoleInput);
    this->moveCursor (QTextCursor::End);
    this->insertPlainText (input);
    consoleInput = "";
}


std::string ConsoleWindow::getOutPut(){
    return consoleInput;
}

// The function that reads the console
void ConsoleWindow::readConsole(){
    auto start = this->cursor;

}

void ConsoleWindow::clearStringBuff(){
    consoleInput = buf.toStdString();
    std::string returned = buf.toStdString();
    buf.clear();

   QString input = QString::fromStdString ("\n");
    this->moveCursor (QTextCursor::End);
    this->insertPlainText (input);
   this->setReadOnly(true);
}


void ConsoleWindow::write(std::string inputString){
        consoleInput = inputString;
        emit writeSignal();
     }


std::string ConsoleWindow::read(){
    //readWindow = true;
    emit readSignal();
    return consoleInput;
}

void ConsoleWindow::moveCursorToEnd(){
     this->moveCursor (QTextCursor::End);
 }

void ConsoleWindow::keyPressEvent(QKeyEvent *event)
 {
     //qDebug() << event->key() << "\t" << Qt::Key_Enter << "\t" << QKeyEvent::Enter;

    if( event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
     {
        emit grabbedKey();
}
     else{

         QPlainTextEdit::keyPressEvent( event );
          buf.push_back(event->text());
     }

 }


void ConsoleWindow::focusOutEvent(QFocusEvent *e){

}

void ConsoleWindow::focusInEvent(QFocusEvent *e){

}

