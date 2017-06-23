(function($) {  
  
    /** 
     * Ĭ�ϲ��� 
     */  
    var defaultOpts = {  
        stage: document, //��̨  
        item: 'resize-item', //�����ŵ�����  
    };  
  
    /** 
     * ������ 
     */  
    var ZResize = function(options) {  
        this.options = $.extend({}, defaultOpts, options);  
        this.init();  
    }  
  
    ZResize.prototype = {  
        init: function() {  
            this.initResizeBox();  
        },  
        /** 
         *  ��ʼ����קitem 
         */  
        initResizeBox: function() {  
            var self = this;  
            $(self.options.item).each(function () {  
                //�������  
                var width = $(this).width();  
                var height = $(this).height();  
                var resizePanel = $('<div class"resize-panel"></div>');  
                resizePanel.css({  
                    width: width,  
                    height: height,  
                    top: 0,  
                    left: 0,  
                    position: 'absolute',  
                    'background-color': 'rgba(0,0,0,0.5)',  
                    cursor: 'move',  
                    display: 'none'  
                });  
                self.appendHandler(resizePanel, $(this));  
                /** 
                 * �������Ƶ� 
                 */  
                var n = $('<div class="n"></div>');//��  
                var s = $('<div class="s"></div>');//��  
                var w = $('<div class="w"></div>');//��  
                var e = $('<div class="e"></div>');//��  
                var ne = $('<div class="ne"></div>');//����  
                var nw = $('<div class="nw"></div>');//����  
                var se = $('<div class="se"></div>');//����  
                var sw = $('<div class="sw"></div>');//����  
  
                //��ӹ�����ʽ  
                self.addHandlerCss([n, s, w, e, ne, nw, se, sw]);  
                //��Ӹ�����ʽ  
                n.css({  
                    'top': '-4px',  
                    'margin-left': '-4px',  
                    'left': '50%',  
                    'cursor': 'n-resize'  
                });  
                s.css({  
                    'bottom': '-4px',  
                    'margin-left': '-4px',  
                    'left': '50%',  
                    'cursor': 's-resize'  
                });  
                e.css({  
                    'top': '50%',  
                    'margin-top': '-4px',  
                    'right': '-4px',  
                    'cursor': 'e-resize'  
                });  
                w.css({  
                    'top': '50%',  
                    'margin-top': '-4px',  
                    'left': '-4px',  
                    'cursor': 'w-resize'  
                });  
                ne.css({  
                    'top': '-4px',  
                    'right': '-4px',  
                    'cursor': 'ne-resize'  
                });  
                nw.css({  
                    top: '-4px',  
                    'left': '-4px',  
                    'cursor': 'nw-resize'  
                });  
                se.css({  
                    'bottom': '-4px',  
                    'right': '-4px',  
                    'cursor': 'se-resize'  
                });  
                sw.css({  
                    'bottom': '-4px',  
                    'left': '-4px',  
                    'cursor': 'sw-resize'  
                });  
  
                // �����Ŀ  
                self.appendHandler([n, s, w, e, ne, nw, se, sw], resizePanel);  
                  
                //����ק�����¼�  
                self.bindResizeEvent(resizePanel, $(this));  
  
                //�󶨴����¼�  
                self.bindTrigger($(this));  
            });  
            self.bindHidePanel();  
        },  
        //���Ƶ㹫����ʽ  
        addHandlerCss: function(els) {  
            for(var i = 0; i < els.length; i++) {  
                el = els[i];  
                el.css({  
                    position: 'absolute',  
                    width: '8px',  
                    height: '8px',  
                    background: '#ff6600',  
                    margin: '0',  
                    'border-radius': '2px',  
                    border: '1px solid #dd5500',  
                });  
            }  
        },  
        /** 
         *  �������� 
         */  
        appendHandler: function(handlers, target) {  
            for(var i = 0; i < handlers.length; i++) {  
                el = handlers[i];  
                target.append(el);  
            }  
        },  
        /** 
         *  ��ʾ��ק��� 
         */  
        triggerResize: function(el) {  
            var self = this;  
            el.siblings(self.options.item).children('div').css({  
                display: 'none'  
            });  
            el.children('div').css({  
                display: 'block'  
            });  
        },  
        /** 
         * ��ק�¼����� ����8�����ŵ�  ��һ����קλ�� 
         */  
        bindResizeEvent: function(el) {  
  
            var self = this;  
            var ox = 0; //ԭʼ�¼�xλ��  
            var oy = 0; //ԭʼ�¼�yλ��  
            var ow = 0; //ԭʼ���  
            var oh = 0; //ԭʼ�߶�  
  
            var oleft = 0; //ԭʼԪ��λ��  
            var otop = 0;  
            var org = el.parent('div');  
  
            //��  
            var emove = false;  
            el.on('touchstart','.e', function(e) {  
                ox = e.pageX;//ԭʼxλ��  
                ow = el.width();  
                emove = true;  
            });  
  
            //��  
            var smove = false;  
            el.on('touchstart','.s', function(e) {  
                oy = e.pageY;//ԭʼxλ��  
                oh = el.height();  
                smove = true;  
            });  
  
            //��  
            var wmove = false;  
            el.on('touchstart','.w', function(e) {  
                ox = e.pageX;//ԭʼxλ��  
                ow = el.width();  
                wmove = true;  
                oleft = parseInt(org.css('left').replace('px', ''));  
            });  
  
            //��  
            var nmove = false;  
            el.on('touchstart','.n', function(e) {  
                oy = e.pageY;//ԭʼxλ��  
                oh = el.height();  
                nmove = true;  
                otop = parseInt(org.css('top').replace('px', ''));  
            });  
  
            //����  
            var nemove = false;  
            el.on('touchstart','.ne', function(e) {  
                ox = e.pageX;//ԭʼxλ��  
                oy = e.pageY;  
                ow = el.width();  
                oh = el.height();  
                nemove = true;  
                otop = parseInt(org.css('top').replace('px', ''));  
            });  
  
            //����  
            var nwmove = false;  
            el.on('touchstart','.nw', function(e) {  
                ox = e.pageX;//ԭʼxλ��  
                oy = e.pageY;  
                ow = el.width();  
                oh = el.height();  
                otop = parseInt(org.css('top').replace('px', ''));  
                oleft = parseInt(org.css('left').replace('px', ''));  
                nwmove = true;  
            });  
  
            //����  
            var semove = false;  
            el.on('touchstart','.se', function(e) {  
                ox = e.pageX;//ԭʼxλ��  
                oy = e.pageY;  
                ow = el.width();  
                oh = el.height();  
                semove = true;  
            });  
  
            //����  
            var swmove = false;  
            el.on('touchstart','.sw', function(e) {  
                ox = e.pageX;//ԭʼxλ��  
                oy = e.pageY;  
                ow = el.width();  
                oh = el.height();  
                swmove = true;  
                oleft = parseInt(org.css('left').replace('px', ''));  
            });  
  
            //��ק  
            var drag = false;  
            el.on('touchstart', function(e) {  
                ox = e.pageX;//ԭʼxλ��  
                oy = e.pageY;  
                otop = parseInt(org.css('top').replace('px', ''));  
                oleft = parseInt(org.css('left').replace('px', ''));  
                drag = true;  
            });  
  
            $(self.options.stage).on('mousemove', function(e) {  
                if(emove) {  
                    var x = (e.pageX - ox);  
                    el.css({  
                        width: ow + x  
                    });  
                    org.css({  
                        width: ow + x  
                    });  
                } else if(smove) {  
                    var y = (e.pageY - oy);  
                    el.css({  
                        height: oh + y  
                    });  
                    org.css({  
                        height: oh + y  
                    });  
                } else if(wmove) {  
                    var x = (e.pageX - ox);  
                    el.css({  
                        width: ow - x,  
                        // left: oleft + x  
                    });  
                    org.css({  
                        width: ow - x,  
                        left: oleft + x  
                    });  
                } else if(nmove) {  
                    var y = (e.pageY - oy);  
                    el.css({  
                        height: oh - y,  
                        // top: otop + y  
                    });  
                    org.css({  
                        height: oh - y,  
                        top: otop + y  
                    });  
                } else if(nemove) {  
                    var x = e.pageX - ox;  
                    var y = e.pageY - oy;  
                    el.css({  
                        height: oh - y,  
                        // top: otop + y,  
                        width: ow + x  
                    });  
                    org.css({  
                        height: oh - y,  
                        top: otop + y,  
                        width: ow + x  
                    });  
                } else if(nwmove) {  
                    var x = e.pageX - ox;  
                    var y = e.pageY - oy;  
                    el.css({  
                        height: oh - y,  
                        // top: otop + y,  
                        width: ow - x,  
                        // left: oleft + x  
                    });  
                    org.css({  
                        height: oh - y,  
                        top: otop + y,  
                        width: ow - x,  
                        left: oleft + x  
                    });  
                } else if(semove) {  
                    var x = e.pageX - ox;  
                    var y = e.pageY - oy;  
                    el.css({  
                        width: ow + x,  
                        height: oh + y  
                    });  
                    org.css({  
                        width: ow + x,  
                        height: oh + y  
                    });  
                } else if(swmove) {  
                    var x = e.pageX - ox;  
                    var y = e.pageY - oy;  
                    el.css({  
                        width: ow - x,  
                        // left: oleft + x,  
                        height: oh + y  
                    });  
                    org.css({  
                        width: ow - x,  
                        left: oleft + x,  
                        height: oh + y  
                    });  
                } else if(drag) {  
                    var x = e.pageX - ox;  
                    var y = e.pageY - oy;  
                    org.css({  
                        left: oleft + x,  
                        top: otop + y  
                    });  
                }  
            }).on('touchend', function(e) {  
               emove = false;  
               smove = false;  
               wmove = false;  
               nmove = false;  
               nemove = false;  
               nwmove = false;  
               swmove = false;  
               semove = false;  
               drag = false;  
            });  
        },  
        /** 
         *  ���item��ʾ��ק��� 
         */  
        bindTrigger: function(el) {  
            var self = this;  
            el.on('tauch', function(e) {  
                e.stopPropagation();  
                self.triggerResize(el);  
            });  
        },  
        /** 
         *  �����̨�������� ����������� 
         */  
        bindHidePanel: function(el) {  
            var stage = this.options.stage;  
            var item = this.options.item;  
            $(stage).bind('touch', function() {  
                $(item).children('div').css({  
                    display: 'none'  
                });  
            })  
        }  
    }  
  
    window.ZResize = ZResize;  
  
})(jQuery); 