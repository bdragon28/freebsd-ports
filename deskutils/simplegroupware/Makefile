# Created by: jamrich.majo@gmail.com
# $FreeBSD$

PORTNAME=	simplegroupware
PORTVERSION=	0.745
CATEGORIES=	deskutils
MASTER_SITES=	SF/simplgroup/${PORTNAME}/${PORTVERSION}/
DISTNAME=	SimpleGroupware_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Groupware is an open source enterprise application

IGNORE_WITH_PHP=	70 71 72 73

NO_BUILD=	yes
USES=		apache:run,2.2+
USE_MYSQL=	yes
USE_PHP=	mysql

SUB_FILES=	pkg-message

SHAREOWN=	${WWWOWN}
SHAREGRP=	${WWWGRP}

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>
