// fragment shader

#version 150

in vec2 texCoordVarying;
out vec4 outputColor;

uniform float time;
uniform sampler2D tex;


float random (in vec2 _st) {
    return fract(sin(dot(_st.xy,
                         vec2(12.9898,78.233)))*
        43758.5453123);
}

// Based on Morgan McGuire @morgan3d
// https://www.shadertoy.com/view/4dS3Wd
float noise (in vec2 _st) {
    vec2 i = floor(_st);
    vec2 f = fract(_st);

    // Four corners in 2D of a tile
    float a = random(i);
    float b = random(i + vec2(1.0, 0.0));
    float c = random(i + vec2(0.0, 1.0));
    float d = random(i + vec2(1.0, 1.0));

    vec2 u = f * f * (3.0 - 2.0 * f);

    return mix(a, b, u.x) +
            (c - a)* u.y * (1.0 - u.x) +
            (d - b) * u.x * u.y;
}

#define NUM_OCTAVES 5

float fbm ( in vec2 _st) {
    float v = 0.0;
    float a = 0.5;
    vec2 shift = vec2(100.0);
    // Rotate to reduce axial bias
    mat2 rot = mat2(cos(0.5), sin(0.5),
                    -sin(0.5), cos(0.50));
    for (int i = 0; i < NUM_OCTAVES; ++i) {
        v += a * noise(_st);
        _st = rot * _st * 2.0 + shift;
        a *= 0.5;
    }
    return v;
}

//  Function from Iñigo Quiles
//  https://www.shadertoy.com/view/MsS3Wc
vec3 hsb2rgb( in vec3 c ){
    vec3 rgb = clamp(abs(mod(c.x*6.0+vec3(0.0,4.0,2.0),
                             6.0)-3.0)-1.0,
                     0.0,
                     1.0 );
    rgb = rgb*rgb*(3.0-2.0*rgb);
    return c.z * mix(vec3(1.0), rgb, c.y);
}


void main()
{
    vec2 st = texCoordVarying.xy;
    vec4 tex_color = texture(tex, st);

    float edge = texture(tex, st).a;

    // float stepSize = 0.01;// * sin(time*0.1);
    // float edge = 0.;

    // for(int i=-1; i<=1; i++) {
    //     for(int j=-1; j<=1; j++) {
    //         vec2 p = vec2(float(i)*stepSize, float(j)*stepSize);
    //         edge += texture(tex, st+p).a;
    //     }
    // }
    // edge = edge / 9.;

    

    // vec3 col;
    // float f = fbm(3.*st +fbm(4.*st + time));//fbm(1.2*st + fbm(0.7*st + fbm(0.3*st + time)));
    // col = vec3(fract(f*8.));

    st *= 2.;
    st -= 1.;

    float h = sin(time+st.x) * 0.5 + 0.5;
    h = mix(0.721, 0.912, h);
    float s = cos(time+st.y) * 0.5 + 0.5;
    s = mix(0.8, 1., s);
    float b = sin(st.x+st.y-time) * 0.5 + 0.5;
    b = mix(0., 0.8, b);
    
    vec3 col = hsb2rgb(vec3(h, s, b));

    vec4 color = vec4(col, 1.);
    outputColor = color * edge;
}