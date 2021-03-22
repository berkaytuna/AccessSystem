# AccessSystem

An access control system using Qt Framework.

Operations are controlled through GUI developed in Qml using Qt Quick. This is the folder "RaspberryDemoQml". There is also a desktop UI application, which is written in C++ using Qt Widgets and layout classes. This is the folder "serverTest2".

The embedded Qml application also hosts a server to communicate with the desktop application. The desktop application is connected to this server via QAbstractSocket operations. When connected, an immediate exchange takes place, which lets the desktop application to get stored QSettings information over connected socket. Therefore, the user can control the settings through desktop application. Changes take immediate effect without need to reboot, thanks to Qt notification system.

Whole design is based on observer pattern, which would mean callbacks/delegates in other frameworks and signal/slot system in Qt. To avoid unnecessary long, clumsy code structure and endless chains of callbacks, i have also introduced a QSettings objects in both Qml embedded and C++ desktop application. All settings in Qml are controlled through this C++ object, which lets us to make changes whenever we want and wherever we want. The QSettings object is the key element of this design pattern, which does not respect any inheritance or signal/slot conventions, but behaves standalone. It is passed to every object through its constructor as a pointer. It is a live object, that is living outside of scopes of classes and their functions. A live settings object, whose parameters can be modified and will take effect instantly, any time, anywhere, accross both Qml and C++.

Dependencies: Qt, bcm2835
