#ifndef ELACONTENTDIALOG_H
#define ELACONTENTDIALOG_H
#include <QAbstractNativeEventFilter>
#include <QDialog>

#include "ElaPropertyHelper.h"

class ElaContentDialogPrivate;
class ELA_EXPORT ElaContentDialog : public QDialog
{
    Q_OBJECT
    Q_Q_CREATE(ElaContentDialog)
public:
    explicit ElaContentDialog(QWidget* parent);
    ~ElaContentDialog();
    Q_SLOT virtual void onLeftButtonClicked();
    Q_SLOT virtual void onMiddleButtonClicked();
    Q_SLOT virtual void onRightButtonClicked();
    void setCentralWidget(QWidget* centralWidget);

    void setLeftButtonText(QString text);
    void setMiddleButtonText(QString text);
    void setRightButtonText(QString text);

    enum ButtonType {
        None,
        Cancel,
        No,
        Yes,
    };

    enum DialogType {
        Notify,          //<! buttons: ok
        Confirm,         //<! buttons: no, yes
        ConfirmOrCancel, //<! buttons: cancel, no, yes
    };

    static int showMessageBox(
        QWidget*                       parent,
        const QString&                 title,
        const QString&                 content,
        DialogType                     type   = Confirm,
        const QMap<QString, QVariant>& config = QMap<QString, QVariant>());

Q_SIGNALS:
    Q_SIGNAL void leftButtonClicked();
    Q_SIGNAL void middleButtonClicked();
    Q_SIGNAL void rightButtonClicked();

protected:
    virtual void showEvent(QShowEvent* event) override;
    virtual void closeEvent(QCloseEvent* event) override;
    virtual void paintEvent(QPaintEvent* event) override;
#if (QT_VERSION == QT_VERSION_CHECK(6, 5, 3) || QT_VERSION == QT_VERSION_CHECK(6, 6, 0))
    bool eventFilter(QObject* obj, QEvent* event) override;
#endif

#ifdef Q_OS_WIN
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    virtual bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;
#else
    virtual bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;
#endif
#endif
};

#endif // ELACONTENTDIALOG_H
