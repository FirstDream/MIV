#pragma once

#include <QObject>
#include <QAction>

#include "Id.h"

namespace MivQt
{
class Context;

class Command : public QObject
{
	Q_OBJECT
public:

	enum CommandAttribute 
	{
		CA_Hide = 1,
		CA_UpdateText = 2,
		CA_UpdateIcon = 4,
		CA_NoneConfigurable = 8

	};

	Q_DECLARE_FLAGS(CommandAttributes, CommandAttribute)

	virtual void setDefaultKeySequence() const = 0;
	virtual QKeySequence defaultKeySequence() const = 0;
	virtual QKeySequence keySequence() = 0;

	//默认是用QAction的Text 或shortcuts 的 whatsThis;
	virtual void setDescription(const QString &text) = 0;
	virtual QString description() = 0;
	virtual Id id() const = 0;

	virtual QAction* action() = 0;
	virtual Context context() = 0;
	
	virtual void setAttribute(CommandAttribute attr) = 0;
	virtual void removeAttribute(CommandAttribute attr) = 0;
	virtual bool hasAttribute(CommandAttribute attr) const = 0;

	virtual void setKeySequence(const QKeySequence &key) = 0;
	virtual QString stringWithAppendedShortcut(const QString &str) const = 0;
	void augmentActionWithShortcutToolTip(QAction *action) const;
	static QToolButton *toolButtonWithAppendedShortcut(QAction *action, Command *cmd);

	virtual bool isScriptable() const = 0;
	virtual bool isScriptable(const Context &) const = 0;

signals:
	void keySequenceChanged();
	void activeStateChanged();

};

}