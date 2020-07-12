!equals(_PRO_FILE_PWD_, $$OUT_PWD) {
    # Final destination for a plugin
    # Known issue: if something changed in plugin - qmake should be run to deploy qml folder and qmldir file
    system(python3 deployment.py --install-path $$DESTDIR)
}
