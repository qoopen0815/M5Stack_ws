# M5Stack_ws

## How to setup develop environment

### Install

```bash
sudo apt-get install arduino
sudo apt-get install python-pip
pip install platformio
```

### PATH

pass the platformio's path

```bash
export PATH=${PATH}:/home/pi/.local/bin
```

PATH が通ったか確認し、次回ログイン時は勝手に PATH が通るようにします。

```bash
which platformio
echo 'export PATH=${PATH}:/home/pi/.local/bin' >> ~/.bashrc
```

※which コマンドの結果、見つからなかった場合は platformio が上記とは別の場所にインストールされています。
次のコマンドで見つけ出しましょう。

```bash
sudo find / -type f -name 'platformio'
```

## How to apply platformio

Move to target arduino project directory.
And, initialize platformio.

```bash
cd hoge_project
platformio init --board=m5stack
```

```bash
echo 'upload_port = /dev/ttyACM0' >> platformio.ini
cat platformio.ini
```

finish