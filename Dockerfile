FROM gcc as builder
WORKDIR /usr/local/src

COPY * ./

CMD make install

FROM alpine
WORKDIR /srv

COPY --from=builder /usr/local/src/asn1ify /srv/

VOLUME /mnt

RUN asn1ify /mnt
