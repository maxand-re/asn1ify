FROM arch

CMD yay -S asn1ify

VOLUME /mnt

RUN asn1ify /mnt
