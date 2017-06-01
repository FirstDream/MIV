#pragma once

#include "mivqt_global.h"

#include <QObject>
#include <QHash>
#include <QAction>

namespace MivQt
{

class Command;
class Id;
class ActionContainer;

class MIVQT_EXPORT ActionManager: public QObject
{
	Q_OBJECT
public:

	static ActionManager* instance();

	static ActionContainer* createMenu(Id id);
	static ActionContainer* createMenuBar(Id id);

	static Command* registerAction(QAction* act, Id id, const Context &context = Context(Constants::C_GLOBAL), bool scriptable = false);
	static void unregisterAction(QAction* act, Id id);

	static Command* command(Id id);

	static ActionContainer* actionContainer(Id id);
	static QList<Command*> commands();

private:
	static void saveSettings();
	static void setContext(const Context& context);

	ActionManager();
	~ActionManager();
	//QHash<ID, >;

};

}