package ch.kripp.spaceapps.serviceproviders;

import ch.kripp.spaceapps.domain.env.EnvironmentInfo;
import ch.kripp.spaceapps.env.EnvironmentServiceBean;
import javax.annotation.ManagedBean;
import javax.ejb.EJB;
import javax.ejb.LocalBean;
import javax.ejb.Stateless;
import javax.enterprise.context.RequestScoped;
import javax.enterprise.inject.Any;
import javax.enterprise.inject.Default;
import javax.inject.Inject;
import javax.inject.Named;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.UriInfo;
import javax.ws.rs.PathParam;
import javax.ws.rs.Consumes;
import javax.ws.rs.PUT;
import javax.ws.rs.Path;
import javax.ws.rs.GET;
import javax.ws.rs.Produces;

/**
 * REST Web Service
 *
 * @author frank
 */
@Path("environment")
@ManagedBean
public class EnvironmentResource {

    @Context
    private UriInfo context;
    
    @Inject
    private EnvironmentServiceBean environmentService; 

    /**
     * Creates a new instance of GenericResource
     */
    public EnvironmentResource() {
    }

    /**
     * Retrieves representation of an instance of ch.kripp.spaceapps.serviceproviders.GenericResource
     * @return an instance of java.lang.String
     */
    @GET
    @Produces("application/json")
    public EnvironmentInfo getJson() {
        //TODO return proper representation object
        return this.environmentService.getEnvironmentIdentifier();
    }

    /**
     * PUT method for updating or creating an instance of GenericResource
     * @param content representation for the resource
     * @return an HTTP response with content of the updated or created resource.
     */
    @PUT
    @Consumes("application/json")
    public void putJson(String content) {
    }
}
