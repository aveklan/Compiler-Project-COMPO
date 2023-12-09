#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

#define SAFE_FREE(ptr) if ((ptr) != NULL) free((ptr));

/*
YOU HAVE THE COMPLETE THE FUNCTIONS BELOW!

To know the attributes of objects like SvgCoord, SvgCoordList, SvgInst, DOM, etc...
please check the ast.h file!

To access or set an attribute of a object defined as pointer (with the *):
my_object->my_attribute

my_object->my_attribute = something;
*/


SvgCoord* new_svg_coord(int x, int y) {
    SvgCoord* svg_coord = malloc(sizeof(SvgCoord));

    // COMPLETE HERE

    return svg_coord;
}

SvgCoordList* new_svg_coord_list(SvgCoord* svg_coord) {
    SvgCoordList* svg_coord_list = malloc(sizeof(SvgCoordList));

    // COMPLETE HERE

    return svg_coord_list;
}

SvgInst* new_svg_inst(SvgInstKind kind, SvgCoordList* coords) {
    SvgInst* svg_inst = malloc(sizeof(SvgInst));

    // COMPLETE HERE

    return svg_inst;
}

SvgList* new_svg_list(SvgInst* svg) {
    SvgList* svg_list = malloc(sizeof(SvgList));

    // COMPLETE HERE

    return svg_list;
}

DOM* new_dom(DomElement dom_el, DomList* children) {
    DOM* dom = malloc(sizeof(DOM));

    // COMPLETE HERE

    return dom;
}

DomList* new_dom_list(DOM* dom) {
    DomList* dom_list = malloc(sizeof(DomList));

    // COMPLETE HERE

    return dom_list;
}

/*
END OF THE COMPLETION.
----------------------
YOU DO NOT HAVE TO CHANGE THE FUNCTIONS BELOW.
*/

void free_svg_coord_list(SvgCoordList* svg_coord_list) {
    SvgCoordList* curr = svg_coord_list;

    while (curr != NULL) {
        if (curr->coord != NULL) {
            free(curr->coord);
        }
        SvgCoordList* prev = curr;
        curr = curr->next;
        free(prev);
    }
}

void free_svg_inst(SvgInst* svg_inst) {
    if (svg_inst == NULL) return;
    if (svg_inst->coords) free_svg_coord_list(svg_inst->coords);

    SAFE_FREE(svg_inst->text);
    SAFE_FREE(svg_inst->anchor);
    SAFE_FREE(svg_inst->color_stroke);
    SAFE_FREE(svg_inst->color_fill);

    free(svg_inst);
}

void free_svg_list(SvgList* svg_list) {
    SvgList* curr = svg_list;

    while (curr != NULL) {
        if (curr->svg != NULL) free_svg_inst(curr->svg);
        SvgList* prev = curr;
        curr = curr->next;
        free(prev);
    }
}

void free_dom(DOM* dom) {
    if (dom == NULL) return;

    free_dom_list(dom->children);
    free_svg_list(dom->svg_children);

    SAFE_FREE(dom->text);
    SAFE_FREE(dom->url);

    free(dom);
}

void free_dom_list(DomList* dom_list) {
    DomList* curr = dom_list;

    while (curr != NULL) {
        if (curr->dom != NULL) free_dom(curr->dom);
        DomList* prev = curr;
        curr = curr->next;
        free(prev);
    }
}
