#include <QLineEdit>
#include <QFormLayout>

#include "serverwindow.h"
#include "constants.h"

ServerWindow::ServerWindow(Parameters *inSettings, QWidget *parent)
    : TabWindow(inSettings, parent)
{
    setLayout(layout);

    createGroups(cst::groupNames.server);

    // Group 1: Connection
    items = { new QLineEdit};
    QVector <QString> labelNames = { cst::labelNames.lines[3] };
    for (int i = 0; i < items.size(); i++) {
        settings->lines.push_back(dynamic_cast<QLineEdit*>(items[i]));
    }
    createFormLayout(labelNames, items, 0);
}
