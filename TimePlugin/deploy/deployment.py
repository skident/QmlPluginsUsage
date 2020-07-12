# coding: utf-8

#usage: python3 deployment.py --install-path /Users/skident/Qt5.14.2/5.14.2/clang_64/qml/com/gits/time

import getopt, sys
import os
import os.path
from os import path
import shutil
from distutils.dir_util import copy_tree

def main(argv):
    usage = "Usage : deployment.py\n"
    usage += "\t--install-path <install_path>\n"
    usage += "\t--qml-folder-path <qml_folder_path>\n"
    usage += "\t--qmldir-path <qmldir_path>\n"
    
    
    try:
        opts,args = getopt.getopt(argv,"hn:",["help", "install-path=", "qml-folder-path=", "qmldir-path="])
    except getopt.GetoptError as e:
        print(e)

        print(usage)
        sys.exit(2)


    install_path = ""
    qml_folder_path = "../qml"
    qmldir_path = "../qmldir"

    for opt, arg in opts:
        if (opt == '--help' or opt == '-h'):
            print(usage)
            sys.exit(0)

        if (opt == '--install-path'):
            print ("INSTALL PATH:",arg)
            install_path = arg
            
        if (opt == '--qml-folder-path'):
            print ("QML FOLDER PATH:",arg)
            qml_folder_path = arg
        
        if (opt == '--qmldir-path'):
            print ("QMLDIR PATH:",arg)
            qmldir_path = arg

    if path.exists(install_path):
        shutil.rmtree(install_path)
    
    os.makedirs(install_path)
    shutil.copy2(qmldir_path, install_path)
    copy_tree(qml_folder_path, install_path + "/qml/")


if __name__ == '__main__':
    main(sys.argv[1:])
