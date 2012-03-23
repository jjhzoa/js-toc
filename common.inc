<?php

/**
 * function to create a easy TOC for any module. 
 * @param array $options array ('exclude' => 'h1', 'content' => '#content_article'); 
 */
function jstoc_set_toc ($options) {
    template::setJs('/templates/js-toc/jquery.toc-1.1.1.min.js');
    template::setCss('/templates/js-toc/toc.css');
    if (!isset($options['exclude'])) {
        $options['exclude'] = 'h1';
    }
    if (!isset($options['content'])) {
        $options['context'] = '#content';
    }
    ob_start();
?>
$(document).ready(function() {
    $('#toc').toc({exclude: '<?=$options['exclude']?>' , context: '<?=$options['context']?>', autoId: true});
});

<?php
    $content = ob_get_contents();
    ob_end_clean();
    template::setStringJs($content);
}
