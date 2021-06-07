# asn1ify
Transform classic path to ASN.1-like path


- [Examples](#examples)
- [Installation](#installation)
- [Documentation](#documentation)

## Examples

#### Before:
```
example/
├── bar
├── file.txt
└── foo
    ├── bar
    │   └── foo
    └── file.txt
```

#### Execute:
```sh
asn1ify example/
```

#### After:
```sh
example/
├── 00 # file.txt
├── 01 # foo
│   ├── 00 # file.txt
│   └── 01 # bar
│       └── 00 # foo
└── 02 # bar
```
*File are renamed first, and folder after, so it's in this order every time you execute this command.*


## Installation 

#### Arch Linux:
asn1ify is in AUR, you can install it with `yay` or other tools:
```sh
yay -S asn1ify
```

#### Other distribs (Manual Install):
```sh
git clone https://github.com/RyFax/asn1ify
cd asn1ify
sudo make install
```


## Documentation

> TODO
