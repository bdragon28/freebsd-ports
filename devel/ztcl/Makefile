# Created by: Denis Shaposhnikov <dsh@vlink.ru>
# $FreeBSD$

PORTNAME=	ztcl
DISTVERSION=	1.0b4
PORTREVISION=	1
CATEGORIES=	devel tcl
MASTER_SITES=	http://download.gna.org/ztcl/1.0/
DISTNAME=	${PORTNAME}_${DISTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zlib extension library for the Tcl

LICENSE=	LGPL21

DEPRECATED=	Unfetchable, unmaintained, info page unbuildable with recent makeinfo
EXPIRATION_DATE=	2018-12-03
BROKEN=		Does not build with recent texinfo

LIB_DEPENDS=	libtclmore0.so:devel/tclmore

OPTIONS_DEFINE=	DOCS

USES=		gmake tcl:tea
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_src$//}
LLD_UNSAFE=	yes

INFO=		${PORTNAME} ${PORTNAME}-zlib

CONFIGURE_ARGS=	--with-tclmorescripts=${LOCALBASE}/libexec/tclmore \
		--enable-threads
MAKE_ENV+=	STAGEDIR=${STAGEDIR}
CPPFLAGS+=	-I ${LOCALBASE}/include
LDFLAGS+=	-L ${LOCALBASE}/lib

PORTDOCS=	*

post-extract:
	${MV} ${WRKSRC}/doc/zlib.texi ${WRKSRC}/doc/${PORTNAME}-zlib.texi

.include <bsd.port.mk>
