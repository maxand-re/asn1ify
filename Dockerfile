FROM gcc as builder
WORKDIR /usr/local/src

COPY * ./

RUN make install

FROM archlinux
WORKDIR /srv

COPY --from=builder /usr/local/src/asn1ify /srv/

RUN chmod +x ./asn1ify

VOLUME /mnt/

CMD ["/srv/asn1ify", "/mnt"]