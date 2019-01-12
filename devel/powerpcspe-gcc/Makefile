# $FreeBSD$

PKGNAMEPREFIX=	powerpcspe-
PLIST=	${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../powerpc64-gcc
FREEBSD_EXTENSION=	yes
CONFIGURE_ARGS+=	--enable-obsolete
BU_PREFIX=	e500v2-unknown-${OPSYS:tl}${OSREL}

.include "${MASTERDIR}/Makefile"
