#ifndef ELASCROLLPAGEPRIVATE_H
#define ELASCROLLPAGEPRIVATE_H

#include <QMap>
#include <QObject>

#include "ElaPropertyHelper.h"
class ElaScrollPage;
class ElaScrollArea;
class QHBoxLayout;
class ElaText;
class QStackedWidget;
class ElaBreadcrumbBar;
class ElaScrollPagePrivate : public QObject
{
    Q_OBJECT
    Q_D_CREATE(ElaScrollPage)
    Q_PROPERTY_CREATE_D(int, BorderRadius)
public:
    explicit ElaScrollPagePrivate(QObject* parent = nullptr);
    ~ElaScrollPagePrivate();
    Q_INVOKABLE void onNavigationRouteBack(QVariantMap routeData);

private:
    QHBoxLayout* _pageTitleLayout{nullptr};
    QStackedWidget* _centralStackedWidget{nullptr};
    ElaBreadcrumbBar* _breadcrumbBar{nullptr};
    QMap<QString, int> _centralWidgetMap;
    int _navigationTargetIndex{0};
    int _pageTitleSpacing{0};
    bool _isGrabGesture{false};
    void _switchCentralStackIndex(int targetIndex, int lastIndex);
};

#endif // ELASCROLLPAGEPRIVATE_H
