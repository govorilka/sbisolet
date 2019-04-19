#include <QWidget>

QT_BEGIN_NAMESPACE
class QSlider;
class QPushButton;
QT_END_NAMESPACE

class GLWidget;
class MainWindow;

class Window : public QWidget
{
    Q_OBJECT

struct Command
{
    QString name;
    qreal arg1 = 30;
    qreal arg2 = 180;
};

public:
    Window(MainWindow *mw);

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void dockUndock();
    void execCommand(const Command &data);

private:
    QSlider *createSlider();

    GLWidget *glWidget;
    QSlider *xSlider;
    QSlider *ySlider;
    QSlider *zSlider;
    QPushButton *dockBtn;
    MainWindow *mainWindow;
};
