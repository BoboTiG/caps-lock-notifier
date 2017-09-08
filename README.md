# Caps Lock Notifier

![Screenshot](https://rawgithub.com/BoboTiG/caps-lock-notifier/master/screenshots/caps-lock-notifier.png)

- English: Displays a notification icon depending of the `Caps Lock` state.
- Français: Affiche une icône de notification en fonction du verrouillage ou non de la touche des majuscules (`Verr Maj`).

Translated in: english, french.

## Customization

You can easily changes owner informations in the file `src\version.h`.

## Compilation

You will need Qt, then:

    cd src
    qmake -o Makefile CapsLockNotifier.pro
    make
